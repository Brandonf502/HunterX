#include "WhaleIsland.h"

WhaleIsland::WhaleIsland(Area* whaleIslandArea) {
	area = whaleIslandArea;

}

std::string WhaleIsland::locationName(Player& player) {
	Location* currentLocation = player.getCurrentLocation();
	if (currentLocation != nullptr) {
		return currentLocation->getName();
	}
	else {
		return "Unknown Location";
	}
}

void WhaleIsland::movement(Player& player, Input& input) {
	Location* currentLocation = player.getCurrentLocation();
	if (input.action == Action::North && currentLocation->north != nullptr) {
		if (currentLocation->north->getName() == "North") {
			currentLocation = currentLocation;
		}
		else {
			player.setCurrentLocation(currentLocation->north);

		}

	}
	else if (input.action == Action::East && currentLocation->east != nullptr) {
		if (currentLocation->east->getName() == "East") {
			currentLocation = currentLocation;
		}
		else {
			player.setCurrentLocation(currentLocation->east);
		}	
	}
	else if (input.action == Action::South && currentLocation->south != nullptr) {
		if (currentLocation->south->getName() == "South") {
			currentLocation = currentLocation;
		}
		else {
			player.setCurrentLocation(currentLocation->south);
		}
	}
	else if (input.action == Action::West && currentLocation->west != nullptr) {
		if (currentLocation->west->getName() == "West") {
			currentLocation = currentLocation;
		}
		else {
			player.setCurrentLocation(currentLocation->west);
		}
	}

}

