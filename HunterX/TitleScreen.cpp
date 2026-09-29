#include "TitleScreen.h"
#include "TypeWrite.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <cstdlib>

void TitleScreen::displayTitle(const std::vector<std::string>& title) {

	for (const std::string& line : title) {
		typeWrite(line);
	}
}



void TitleScreen::titlescreen(int userNum) {

	std::string a = " ==== Hunter X ==== ";
	std::string b = "   1. Play Game ";
	std::string c = "   2. Exit Game ";
	std::string d = " ==== Goodbye! ====";
	std::string e = "== Starting Game... ==";
	std::string f = "==== Invalid Choice... ====";
	std::vector<std::string> title = { a, b, c };

	int choiceOne = 1;
	int choiceTwo = 2;
	
	
	if (userNum == 0) {
		displayTitle(title);
	}


	if (userNum == choiceOne) {
		system("cls");
		title.pop_back();
		title.pop_back();
		title.push_back(e);
		displayTitle(title);
		Sleep(1200);
		
	}
	else if (userNum == choiceTwo) {
		system("cls");
		title.pop_back();
		title.pop_back();
		title.pop_back();
		title.push_back(d);
		displayTitle(title);
		Sleep(1200);
	}
	else if (userNum != choiceOne && userNum != choiceTwo && userNum != 0) {
		system("cls");
		title.pop_back();
		title.pop_back();
		title.pop_back();
		title.push_back(f);
		displayTitle(title);
		Sleep(1200);
		
	}
	return;
}



	
