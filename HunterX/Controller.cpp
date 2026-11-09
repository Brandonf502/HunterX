/*
 * Controller.cpp
 * Converts keyboard input into the shared Input and Action types.
 * Platform macros select the Windows or shared macOS/Linux implementation.
 */
#include "Controller.h"

#include <iostream>
#include <ostream>

#include "Platform.h"

#if defined(HUNTER_WINDOWS)
#include <conio.h>

Input Controller::readAction() {
	// _getch() reads immediately without echoing the key to the console.
	int key = _getch();

	if (key >= '1' && key <= '9') {
		return { Action::Number, key - '0' };
	}

	// Windows extended keys have a prefix followed by a second key code.
	if (key == 0 || key == 224) {
		key = _getch();

		switch (key) {
		case 72: return { Action::North, 0 };
		case 77: return { Action::East, 0 };
		case 80: return { Action::South, 0 };
		case 75: return { Action::West, 0 };
		};
	}

	if (key == 'i' || key == 'I') {
		return { Action::Inventory, 0 };
	}

	if (key == 27) {
		return { Action::Exit, 0 };
	}

	if (key == 'p' || key == 'P') {
		return { Action::Menu, 0 };
	}

	if (key == 'm' || key == 'M') {
		return { Action::Map, 0 };
	}

	if (key == 13) {
		return {Action::Enter, 0};
	}
	if (key == 8) {
		return {Action::Back, 0};
	}
	return { Action::None, 0 };
}

#elif defined(HUNTER_APPLE) || defined(HUNTER_LINUX)
#include <termios.h>
#include <unistd.h>

Input Controller::readAction() {
	// Preserve the user's terminal settings so changes can be undone.
	termios originalSettings{};

	if (tcgetattr(STDIN_FILENO, &originalSettings) == -1) {
		std::cerr << "Unable to read terminal settings" << std::endl;
		return {Action::None, 0};
	}

	termios inputSettings = originalSettings;
	// Disable line buffering (waiting for Enter) and automatic key echo.
	inputSettings.c_lflag &= ~(ICANON | ECHO);
	// Block until one byte arrives; no timeout for the first key byte.
	inputSettings.c_cc[VMIN] = 1;
	inputSettings.c_cc[VTIME] = 0;

	if (tcsetattr(STDIN_FILENO, TCSANOW, &inputSettings) == -1) {
		std::cerr << "Unable to set terminal settings" << std::endl;
		tcsetattr(STDIN_FILENO, TCSANOW, &originalSettings);
		return {Action::None, 0};
	}

	// Store actions instead of returning early: terminal cleanup must run first.
	// Unrecognized input leaves the default action as Action::None.
	Input result;
	unsigned char key = 0;
	ssize_t bytesRead = read(STDIN_FILENO, &key, 1);

	if (bytesRead == 1) {
	if (key >= '1' && key <= '9') {
		result = { Action::Number, key - '0' };
	}

	if (key == 'i' || key == 'I') {
		result = { Action::Inventory, 0 };
	}

	if (key == 'p' || key == 'P') {
		result = { Action::Menu, 0 };
	}

	if (key == 'm' || key == 'M') {
		result = { Action::Map, 0 };
	}

	if (key =='\n' || key == '\r') {
		result = { Action::Enter, 0};
	}

	// Backspace can arrive as DEL (127) or BS (8), depending on the terminal.
	if (key == 127 || key == 8) {
		result = { Action::Back, 0 };
	}

	if (key == 27) {
		// Escape may be a standalone key or the start of an arrow sequence.
		// With VMIN=0, VTIME=1 limits each following read to 0.1 seconds.
		inputSettings.c_cc[VMIN] = 0;
		inputSettings.c_cc[VTIME] = 1;

		if (tcsetattr(STDIN_FILENO, TCSANOW, &inputSettings) == -1) {
			std::cerr << "Unable to configure timed input.\n";
		}
		else {
			unsigned char prefix = 0;
			ssize_t prefixRead = read(STDIN_FILENO, &prefix, 1);

			if (prefixRead == 0) {
				// The timeout expired without a second byte: standalone Escape.
				result = { Action::Exit, 0 };
			}

			else if (prefixRead == 1 && (prefix == '[' || prefix == 'O')) {
				// Common unmodified arrows use ESC [ A-D or ESC O A-D.
				// Other escape sequences are not decoded by this implementation.
				unsigned char direction = 0;
				ssize_t directionRead = read(STDIN_FILENO, &direction, 1);

				if (directionRead == 1) {
					switch (direction) {
						case 'A':
							result = { Action::North, 0 };
							break;
						case 'B':
							result = { Action::South, 0 };
							break;
						case 'C':
							result = { Action::East, 0 };
							break;
						case 'D':
							result = { Action::West, 0 };
							break;
					}
				}

				else if (directionRead == -1) {
					std::cerr << "Unable to read Arrow Key" << std::endl;
				}
			}

			else if (prefixRead == -1) {
				std::cerr << "Unable to read Escape sequence" << std::endl;
			}
		}
	}
	}
	else {
		std::cerr << "Input ended or could not be read" << std::endl;
	}

	// Restore settings after ordinary keys, complete sequences, and read errors.
	// This is normal function cleanup; it does not handle forced termination.
	if (tcsetattr(STDIN_FILENO, TCSANOW, &originalSettings) == -1) {
		std::cerr << "Unable to restore terminal settings.\n";
		return {Action::None, 0};
	}
	return result;
}



#endif
