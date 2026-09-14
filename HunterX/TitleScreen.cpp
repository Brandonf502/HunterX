#include "TitleScreen.h"
#include <iostream>
#include <vector>

void TitleScreen::displayTitle(const std::vector<std::string>& title) {

	for (const std::string& line : title) {
		std::cout << line << std::endl;
	}
}

int TitleScreen::titlescreen() {

	std::string a = " ==== Hunter X ==== ";
	std::string b = "   1. Play Game ";
	std::string c = "   2. Exit Game ";
	std::string d = " ==== Goodbye! ====";
	std::string e = "== Starting Game... ==";
	std::string f = "==== Invalid Choice... ====";
	std::vector<std::string> title = { a, b, c };

	int choiceOne = 1;
	int choiceTwo = 2;
	int userNum;

	displayTitle(title);

	std::cin >> userNum;

	if (userNum == choiceOne) {
		title.pop_back();
		title.pop_back();
		title.push_back(e);
		displayTitle(title);
		
	}
	else if (userNum == choiceTwo) {
		title.pop_back();
		title.pop_back();
		title.pop_back();
		title.push_back(d);
		displayTitle(title);
	}
	else if (userNum!=choiceOne && userNum!=choiceTwo) {
		title.pop_back();
		title.pop_back();
		title.pop_back();
		title.push_back(f);
		displayTitle(title);
		
	}
	return userNum;
}



	
