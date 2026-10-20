#pragma once
#include <fstream>

enum class GameMode {

	TitleScreen,
	MainMenu,
	CharacterCreation,
	LoadSavedState,
	Settings,
	Roaming,
	Battle,
	Inventory,
	Map,
	Narrating,
	Stats,
	Death,
	Exit

};

struct GameState {

	GameMode currentMode = GameMode::TitleScreen;
	GameMode previousMode = GameMode::TitleScreen;
	bool savedGameExists = false;

	bool checkSavedState() {

		std::ifstream saveFile("SavedData.txt");

		if (saveFile.is_open() && saveFile.peek() != EOF) {
			savedGameExists = true;
		}
		else {
			savedGameExists = false;
		}
		return savedGameExists;
	}
	


};

