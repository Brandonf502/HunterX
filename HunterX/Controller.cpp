#include "Controller.h"
#include <conio.h>

Input Controller::readAction() {
	int key = _getch();

	if (key >= '1' && key <= '9') {
		return { Action::Number, key - '0' };
	}

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
	return { Action::None, 0 };
}