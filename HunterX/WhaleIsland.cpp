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
	if (input.action == Action::North && currentLocation->getNorth() != nullptr) {
		if (currentLocation->getNorth()->getName() == "North") {
			currentLocation = currentLocation;
		}
		else {
			player.setCurrentLocation(currentLocation->getNorth());

		}

	}
	else if (input.action == Action::East && currentLocation->getEast() != nullptr) {
		if (currentLocation->getEast()->getName() == "East") {
			currentLocation = currentLocation;
		}
		else {
			player.setCurrentLocation(currentLocation->getEast());
		}	
	}

	else if (input.action == Action::South && currentLocation->getSouth() != nullptr) {
		if (currentLocation->getSouth()->getName() == "South") {
			currentLocation = currentLocation;
		}
		else {
			player.setCurrentLocation(currentLocation->getSouth());
		}
	}
	else if (input.action == Action::West && currentLocation->getWest() != nullptr) {
		if (currentLocation->getWest()->getName() == "West") {
			currentLocation = currentLocation;
		}
		else {
			player.setCurrentLocation(currentLocation->getWest());
		}
	}

}

