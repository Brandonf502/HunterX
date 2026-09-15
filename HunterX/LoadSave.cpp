#include "LoadSave.h"
#include <fstream>
#include <iostream>

std::vector<savedStates> loadSavedGames() {
	std::vector<savedStates> savedGames;

	std::ifstream saveFile("SavedData.txt");

	if (!saveFile.is_open()) {
		return savedGames;
	}
	std::string line;
	savedStates currentSave;
	while (std::getline(saveFile, line)) {
		if (line.empty()) {
			savedGames.push_back(currentSave);
			currentSave = savedStates();
			continue;
		}

		size_t equalsPosition = line.find('=');

		if (equalsPosition != std::string::npos) {
			std::string key = line.substr(0, equalsPosition);
			std::string value = line.substr(equalsPosition + 1);
			if (key == "playerName") {
				currentSave.playerName = value;
			}
			else if (key == "currentHealth") {
				currentSave.currentHealth = std::stoi(value);
			}
		}
		if (!currentSave.playerName.empty()) {
			savedGames.push_back(currentSave);
		}
	}

	return savedGames;
}

int chooseSavedGames(const std::vector<savedStates>& savedGames) {
	if (savedGames.empty()) {
		return -1;
	}
	for (int i = 0; i < savedGames.size(); ++i) {
		std::cout << i + 1 << ". " << savedGames[i].playerName << std::endl;
	}
	int choice;

	std::cout << "Choose Character: ";
	std::cin >> choice;

	if (choice < 1 || choice > savedGames.size()) {
		std::cout << "Invalid choice. \n";
		return -1;
	}
	return choice - 1;
}