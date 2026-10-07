#include "PlayGame.h"
#include "TitleScreen.h"
#include "MainMenu.h"
#include "CharacterCreation.h"
#include "LoadSave.h"
#include <iostream>
#include <cstdlib>
#include "Controller.h"
#include "Roaming.h"

void PlayGame::gameOn() {
	
	GameState state;
	Controller controller;
	state.currentMode = GameMode::TitleScreen;
	map.buildMap();
	
	

	while (state.currentMode != GameMode::Exit) {
		system("cls");

		switch (state.currentMode) {
		case GameMode::TitleScreen:
		{
			TitleScreen titleScreen;
			int userNum = 0;
			titleScreen.titlescreen(userNum);
			Input input = controller.readAction();
			
			
			if (userNum == 0) {
				userNum = input.number;
				titleScreen.titlescreen(userNum);
			}
			
			if (input.number == 1) {
				state.currentMode = GameMode::MainMenu;
			}
			else if (input.number == 2) {
				state.currentMode = GameMode::Exit;
			}
			else if (input.number != 1 && input.number != 2){
				state.currentMode = GameMode::TitleScreen;
			}
			
			break; 
		}

		case GameMode::MainMenu:
		{
			state.checkSavedState();
			if (state.checkSavedState()) {
				MainMenu mainMenu;
				mainMenu.menu();

				Input input = controller.readAction();

				if (input.number == 1) {
					state.currentMode = GameMode::CharacterCreation;
				}
				else if (input.number == 2) {
					state.currentMode = GameMode::LoadSavedState;
				}
				else if (input.number == 3) {
					state.currentMode = GameMode::Settings;
				}
				else if (input.number == 4) {
					state.currentMode = GameMode::Exit;
				}
				else {
					state.currentMode = GameMode::TitleScreen;
				}

			}
			else {
				state.currentMode = GameMode::CharacterCreation;
			}

			break;
		}

		case GameMode::CharacterCreation:
		{
			player = createCharacter();
			player.setCurrentLocation(map.getStartingLocation());
			saveCharacter(player);
			state.currentMode = GameMode::Roaming;

			break;
		}

		case GameMode::LoadSavedState: {
			std::vector<savedStates> savedGames = loadSavedGames();
			chooseSavedGames(savedGames);
			bool playerSelected = false;

			Input input = controller.readAction();

			if (input.number) {
				int index = input.number - 1;

				if (index >= 0 && index < static_cast<int>(savedGames.size())) {
					const savedStates& selectedSave = savedGames[index];
					player = Player(selectedSave.playerName);
					playerSelected = true;
				}
				else {
					std::cout << "Invalid choice.\n";
				}
			}
			if (playerSelected) {
				player.setCurrentLocation(map.getStartingLocation());
				state.currentMode = GameMode::Roaming;
				playerSelected = false;
			}

			break;
		}
			
			
		
		case GameMode::Settings:
			// Handle settings logic
			break;

		case GameMode::Roaming: {
			AreaState roaming;
			while (state.currentMode == GameMode::Roaming) {
				Area* currentArea = player.getCurrentArea(player.getCurrentLocation());
				if (currentArea == nullptr) {
					std::cout << "ERROR: Current location has no Area!\n";
					std::cout << "Location: "
						<< player.getCurrentLocation()->getName()
						<< '\n';

					break;
				}
				std::string currentAreaName = currentArea->name;

				if (currentAreaName == "Whale Island") {
					roaming.currentArea = Roaming::WhaleIsland;
				}
				else if (currentAreaName == "Heavens Arena") {
					roaming.currentArea = Roaming::HeavensArena;
				}
				else if (currentAreaName == "Greed Island") {
					roaming.currentArea = Roaming::GreedIsland;
				}
				roaming.roam(player);
			}
			break;
		}

		case GameMode::Battle:
			// Handle battle logic
			break;

		case GameMode::Inventory:
			// Handle inventory logic
			break;

		case GameMode::Narrating:
			// Handle narrating logic
			break;

		case GameMode::Stats:
			// Handle stats logic
			break;

		case GameMode::Death:
			// Handle death logic
			break;

		default:
			state.currentMode = GameMode::Exit; // Exit the game if an unknown mode is encountered
			break;
		}
	}

	
}


