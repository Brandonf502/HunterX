#include "Roaming.h"
#include "TypeWrite.h"
#include "Controller.h"
#include "WhaleIsland.h"
#include "Player.h"
#include "Area.h"
#include "PlayerRequest.h"
#include <cstdlib>

void AreaState::roam(Player& player) {
	playerRequest = PlayerRequest::None;
	switch (currentArea) {
	case Roaming::WhaleIsland: {
		system("cls");
		typeWrite("======== Whale Island ========\n");
		std::string location = player.getCurrentLocation()->getName();
		typeWrite("    ==== " + location + " ====    \n");
		Input input = Controller().readAction();
		Area* playerArea = player.getCurrentArea(player.getCurrentLocation());
		WhaleIsland whaleIsland(playerArea);
		whaleIsland.movement(player, input);

		if (input.action == Action::Inventory) {
			playerRequest = PlayerRequest::Inventory;
		}
		else if (input.action == Action::Map) {
			playerRequest = PlayerRequest::Map;
		}
		else if (input.action == Action::Menu) {
			playerRequest = PlayerRequest::Stats;
		}
		else if (input.action == Action::Exit) {
			exit(0);
		}
		
		break;
	}
	case Roaming::HeavensArena: {
		typeWrite("======== Heavens Arena ========\n");
		Input input = Controller().readAction();
		break;
	}
	case Roaming::GreedIsland: {
		typeWrite("======== Greed Island ========\n");
		Input input = Controller().readAction();
		break;
	}
	}
}