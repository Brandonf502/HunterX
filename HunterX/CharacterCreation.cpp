#include "CharacterCreation.h"
#include <iostream>
#include <fstream>

bool saveCharacter(const Player& player) {
	std::ofstream saveFile("SavedData.txt");

	if (!saveFile.is_open()) {

		return false;

	}

	saveFile << "playerName=" << player.getName() << '\n';
	saveFile << "currentHealth=" << player.getHealth() << '\n';

	return true;

}

Player createCharacter() {
	std::cout << "Enter your character's name: ";
	std::string playerName;

	std::cin >> playerName;
	return Player(playerName);
}

