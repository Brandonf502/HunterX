#include "Map.h"

#include <format>

#include "Location.h"
#include "Area.h"
#include "Controller.h"
#include "Player.h"
#include "TypeWrite.h"

void Map::buildMap() {

	areas.reserve(3);
	areas.emplace_back("Whale Island");
	Area& whaleIsland = areas.back();


	areas.emplace_back("Heaven's Arena");
	Area& heavensArena = areas.back();

	areas.emplace_back("Greed Island");
	Area& greedIsland = areas.back();

	whaleIsland.next = &heavensArena;
	whaleIsland.previous = &greedIsland;
	heavensArena.next = &greedIsland;
	heavensArena.previous = &whaleIsland;
	greedIsland.next = &whaleIsland;
	greedIsland.previous = &heavensArena;


	whaleIsland.locations.reserve(15);

	whaleIsland.locations.emplace_back("Forest");
	whaleIsland.locations.emplace_back("West Forest");
	whaleIsland.locations.emplace_back("East Forest");
	whaleIsland.locations.emplace_back("South Forest");
	whaleIsland.locations.emplace_back("Mito's House");
	whaleIsland.locations.emplace_back("Swamp");
	whaleIsland.locations.emplace_back("North River");
	whaleIsland.locations.emplace_back("River");
	whaleIsland.locations.emplace_back("South River");
	whaleIsland.locations.emplace_back("Port Town");
	whaleIsland.locations.emplace_back("Port Dock");
	whaleIsland.locations.emplace_back("North");
	whaleIsland.locations.emplace_back("East");
	whaleIsland.locations.emplace_back("South");
	whaleIsland.locations.emplace_back("West");

	Location& Forest = whaleIsland.locations[0];
	Location& westForest = whaleIsland.locations[1];
	Location& eastForest = whaleIsland.locations[2];
	Location& southForest = whaleIsland.locations[3];
	Location& mitoHouse = whaleIsland.locations[4];
	Location& swamp = whaleIsland.locations[5];
	Location& northRiver = whaleIsland.locations[6];
	Location& river = whaleIsland.locations[7];
	Location& southRiver = whaleIsland.locations[8];
	Location& portTown = whaleIsland.locations[9];
	Location& portDock = whaleIsland.locations[10];
	Location& northBorder = whaleIsland.locations[11];
	Location& eastBorder = whaleIsland.locations[12];
	Location& southBorder = whaleIsland.locations[13];
	Location& westBorder = whaleIsland.locations[14];

	mitoHouse.setCoordinates({0,1});
	Forest.setCoordinates({0,0});
	portTown.setCoordinates({0,-1});
	portDock.setCoordinates({0,-2});

	northRiver.setCoordinates({-1,1});
	river.setCoordinates({-1,0});
	southRiver.setCoordinates({-1,-1});

	westForest.setCoordinates({-2,0});

	eastForest.setCoordinates({1,1});
	swamp.setCoordinates({1,0});
	southForest.setCoordinates({1,-1});


	northBorder.setArea(&whaleIsland);
	eastBorder.setArea(&whaleIsland);
	southBorder.setArea(&whaleIsland);
	westBorder.setArea(&whaleIsland);


	Forest.setArea(&whaleIsland);
	Forest.setNorth(&mitoHouse);
	Forest.setEast(&swamp);
	Forest.setSouth(&portTown);
	Forest.setWest(&river);

	eastForest.setArea(&whaleIsland);
	eastForest.setNorth(&northBorder);
	eastForest.setEast(&eastBorder);
	eastForest.setSouth(&swamp);
	eastForest.setWest(&mitoHouse);

	westForest.setArea(&whaleIsland);
	westForest.setNorth(&northRiver);
	westForest.setEast(&river);
	westForest.setSouth(&southRiver);
	westForest.setWest(&westBorder);

	southForest.setArea(&whaleIsland);
	southForest.setNorth(&swamp);
	southForest.setEast(&eastBorder);
	southForest.setSouth(&southBorder);
	southForest.setWest(&portTown);

	mitoHouse.setArea(&whaleIsland);
	mitoHouse.setNorth(&northBorder);
	mitoHouse.setEast(&eastForest);
	mitoHouse.setSouth(&Forest);
	mitoHouse.setWest(&northRiver);

	portTown.setArea(&whaleIsland);
	portTown.setNorth(&Forest);
	portTown.setEast(&southForest);
	portTown.setSouth(&portDock);
	portTown.setWest(&southRiver);

	portDock.setArea(&whaleIsland);
	portDock.setNorth(&portTown);
	portDock.setEast(&eastBorder);
	portDock.setSouth(&southBorder);
	portDock.setWest(&westBorder);

	swamp.setArea(&whaleIsland);
	swamp.setNorth(&eastForest);
	swamp.setEast(&eastBorder);
	swamp.setSouth(&southForest);
	swamp.setWest(&Forest);

	northRiver.setArea(&whaleIsland);
	northRiver.setNorth(&northBorder);
	northRiver.setEast(&mitoHouse);
	northRiver.setSouth(&river);
	northRiver.setWest(&westForest);

	river.setArea(&whaleIsland);
	river.setNorth(&northRiver);
	river.setEast(&Forest);
	river.setSouth(&southRiver);
	river.setWest(&westForest);

	southRiver.setArea(&whaleIsland);
	southRiver.setNorth(&river);
	southRiver.setEast(&portTown);
	southRiver.setSouth(&southBorder);
	southRiver.setWest(&westForest);

	this->northBorder = &northBorder;
	this->eastBorder = &eastBorder;
	this->southBorder = &southBorder;
	this->westBorder = &westBorder;
	

	this->first = &areas[0];
}

Location* Map::getStartingLocation() {
	return &areas[0].locations[4];
}

Map::gridBoundaries Map::getGridBoundaries(Area& area) {
	int maxX;
	int maxY;
	int minY;
	int minX;
	std::vector<Location>& locations = area.getLocations();
	Map::gridBoundaries boundaries{};

	bool bounds = false;
	for (const Location& location : locations) {
		if (location.isBorder()) {
			continue;
		}

		Location::Coordinates position = location.getCoordinates();

		if (!bounds) {
			maxX = position.x;
			maxY = position.y;
			minX = position.x;
			minY = position.y;
			bounds = true;
		}

		if (position.x > maxX) {
			maxX = position.x;
		}
		if (position.x < minX) {
			minX = position.x;
		}
		if (position.y > maxY) {
			maxY = position.y;
		}
		if (position.y < minY) {
			minY = position.y;
		}
	}

	if (locations.empty()) {
		std::cout << "No locations found." << std::endl;
	}
	else {
		boundaries.minimum.x = minX;
		boundaries.minimum.y = minY;

		boundaries.maximum.x = maxX;
		boundaries.maximum.y = maxY;
	}


	return boundaries;
}

std::vector<std::string> Map::canvas(int width,int height) {
	std::vector<std::string> canvas;


	for (int i = 0; i < height; i++) {
		canvas.emplace_back(std::string(width, ' '));
	}

	return canvas;
}

void Map::drawLocations(std::vector<std::string>& blueprint, Area& area, gridBoundaries boundaries) {
	std::vector<Location>& locations = area.getLocations();

	for (Location& location : locations) {
		if (location.isBorder()) {
			continue;
		}
		else {
			Location::Coordinates position = location.getCoordinates();
			int column = position.x - boundaries.minimum.x;
			int row = boundaries.maximum.y - position.y;
			std::string name = location.getName();
			for (std::size_t i = 0; i < name.size(); i++) {
				blueprint[row][column + i] = name[i];
			}
		}
	}
}


void Map::displayMap(Player& player) {
	Area* currentArea = player.getCurrentArea(player.getCurrentLocation());
	bool viewingMap = true;
	int maxX;
	int maxY;
	int minX;
	int minY;
	while (viewingMap) {
		clearScreen();
		std::cout << "======== Map ========\n";
		std::cout << currentArea->name << std::endl;
		std::vector<Location>& locations = currentArea->getLocations();
		bool bounds = false;
		for (const Location& location : locations) {
			bool isBorder = false;
			isBorder = location.isBorder();
			if (isBorder) {
				continue;
			}

			Location::Coordinates position = location.getCoordinates();

			if (!bounds) {
				maxX = position.x;
				maxY = position.y;
				minX = position.x;
				minY = position.y;
				bounds = true;
			}

			if (position.x > maxX) {
				maxX = position.x;
			}
			if (position.x < minX) {
				minX = position.x;
			}
			if (position.y > maxY) {
				maxY = position.y;
			}
			if (position.y < minY) {
				minY = position.y;
			}

		}
		for (int i = maxY; i >= minY; i--) {
			for (int j = minX; j <= maxX; j++) {
				bool foundLocation = false;
				for (Location& location : locations) {
					bool isBorder = false;
					isBorder = location.isBorder();
					if (isBorder) {
						continue;
					}
					Location::Coordinates position = location.getCoordinates();
					if (position.x == j && position.y == i) {
						foundLocation = true;
						std::cout << location.getName();
						if (location.getEast() && !location.getEast()->isBorder()) {
							std::cout << std::string(16 - location.getName().size(), '-');
						}
						else {
							std::cout << std::string(16 - location.getName().size(), ' ');
						}
					}
				}
				if (!foundLocation) {
					std::cout << std::string(16, ' ');
				}
			}
			std::cout << std::endl;
			for (int l = minX; l <= maxX; l++) {
				bool found = false;
				bool diagonal = false;
				for (Location& location : locations) {
					if (location.isBorder()) {
						continue;
					}
					Location::Coordinates position = location.getCoordinates();
					if (position.x == l && position.y == i) {
						if (location.getSouth() && !location.getSouth()->isBorder()) {
							found = true;
							Location& thisLocation = location;
							Location* southNeighbor = location.getSouth();
							Location::Coordinates thisLocationpos = thisLocation.getCoordinates();
							Location::Coordinates southNeighborpos = southNeighbor->getCoordinates();
							diagonal = (
								southNeighborpos.x == thisLocationpos.x &&
								southNeighborpos.y == thisLocationpos.y - 1
								);
						}
					}
				}
				if (found && !diagonal) {
					std::cout << std::string(8, ' ') << "\\" << std::string(7, ' ');
				}
				else if (found && diagonal) {
					std::cout << std::string(8, ' ') << "|" << std::string(7, ' ');
				}
				else {
					std::cout << std::string(16, ' ');
				}
			}

			std::cout << std::endl;
		}



		Input input = Controller().readAction();
		if (input.action == Action::East) {
			currentArea = currentArea->next;
		}
		else if (input.action == Action::West) {
			currentArea = currentArea->previous;
		}
		else if (input.action == Action::Map) {
			viewingMap = false;
		}

	}
}