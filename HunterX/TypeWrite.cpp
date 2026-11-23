#include <iostream>
#include <thread>
#include <chrono>
#include "TypeWrite.h"

void typeWrite(const std::string& letters) {

	for (int i = 0; i < letters.size(); ++i) {
		std::cout << letters[i] << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(45));
	}
	std::cout << std::endl;
}

void clearScreen() {
	std::cout << "\x1B[2J\x1B[3J\x1B[H" << std::flush;
}

void clearContentArea() {
	std::cout << "\x1b[5;1H\x1b[J" << std::flush;
}