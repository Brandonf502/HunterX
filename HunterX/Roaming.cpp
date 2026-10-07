#include "Roaming.h"
#include "TypeWrite.h"
#include "Controller.h"
#include "WhaleIsland.h"
#include "Player.h"
#include "Area.h"
#include <cstdlib>

void AreaState::roam(Player& player) {
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