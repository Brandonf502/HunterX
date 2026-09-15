#include "PlayGame.h"
#include "TitleScreen.h"
#include "MainMenu.h"
#include "CharacterCreation.h"
#include "LoadSave.h"
#include <iostream>

void PlayGame::gameOn() {
	
	GameState state;

	state.currentMode = GameMode::TitleScreen;

	while (state.currentMode != GameMode::Exit) {
		switch (state.currentMode) {
		case GameMode::TitleScreen:
		{
			TitleScreen titleScreen;
			int userNum = titleScreen.titlescreen();
			if (userNum == 1) {
				state.currentMode = GameMode::MainMenu;
			}
			else if (userNum == 2) {
				state.currentMode = GameMode::Exit;
			}
			else if (userNum != 1 && userNum != 2){
				state.currentMode = GameMode::TitleScreen;;
			}
			
			break;
		}

		case GameMode::MainMenu:
		{
			state.checkSavedState();
			if (state.checkSavedState()) {
				MainMenu mainMenu;
				int userNum = mainMenu.menu();
				if (userNum == 1) {
					state.currentMode = GameMode::CharacterCreation;
				}
				else if (userNum == 2) {
					state.currentMode = GameMode::LoadSavedState;
				}
				else if (userNum == 3) {
					state.currentMode = GameMode::Settings;
				}
				else if (userNum == 4) {
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
			Player player = createCharacter();
			saveCharacter(player);
			state.currentMode = GameMode::MainMenu;

			break;
		}

		case GameMode::LoadSavedState: {
			std::vector<savedStates> savedGames = loadSavedGames();
			int choice = chooseSavedGames(savedGames);

			if (choice == -1) {
				state.currentMode = GameMode::MainMenu;
				break;
			}

			savedStates selectedSave = savedGames[choice];
			player = Player(selectedSave.playerName);
			break;
		}
			
		
		case GameMode::Settings:
			// Handle settings logic
			break;

		case GameMode::Roaming:
			// Handle roaming logic
			break;

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


