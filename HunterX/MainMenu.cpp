#include "MainMenu.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

void MainMenu::displayMenu(const std::vector<std::string>& menuOptions) {

	for (const std::string& line : menuOptions) {
		std::cout << line << std::endl;
	}

}

int MainMenu::menu() {
	std::string a = " ====Main Menu ==== ";
	std::string b = "   1. New Game ";
	std::string c = "   2. Load Game ";
	std::string d = "   3. Settings ";
	std::string e = "   4. Exit Game ";

	std::vector<std::string> menuOptions = { a, b, c, d, e, };

	int userNum;

	displayMenu(menuOptions);

	std::cin >> userNum;
	
	return userNum;
}

