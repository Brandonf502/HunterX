#pragma once
#include <vector>
#include <string>

class MainMenu {
private:
	void displayMenu(const std::vector<std::string>& menuOptions);

public: 
	int menu();
};