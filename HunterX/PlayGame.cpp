#include "PlayGame.h"
#include "TitleScreen.h"
#include "MainMenu.h"
#include "CharacterCreation.h"
#include "LoadSave.h"
#include <iostream>
#include "Controller.h"

void PlayGame::gameOn() {
	
	GameState state;
	Controller controller;
	state.currentMode = GameMode::TitleScreen;

	while (state.currentMode != GameMode::Exit) {

		switch (state.currentMode) {
		case GameMode::TitleScreen:
		{
			TitleScreen titleScreen;
			int userNum = 0;
			titleScreen.titlescreen(userNum);
			Input input = controller.readAction();
			userNum = input.number;
			

			
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
			Player player = createCharacter();
			saveCharacter(player);
			state.currentMode = GameMode::MainMenu;

			break;
		}

		case GameMode::LoadSavedState: {
			std::vector<savedStates> savedGames = loadSavedGames();
			chooseSavedGames(savedGames);

			Input input = controller.readAction();

			if (input.number == -1) {
				int index = input.number - 1;

				if (index >= 0 && index < static_cast<int>(savedGames.size())) {
					const savedStates& selectedSave = savedGames[index];
					player = Player(selectedSave.playerName);
					state.currentMode = GameMode::Roaming;
				}
				else {
					std::cout << "Invalid choice.\n";
				}
			}

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


