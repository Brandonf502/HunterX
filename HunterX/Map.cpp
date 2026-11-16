#include "Map.h"

#include <format>
#include <cmath>

#include "Location.h"
#include "Area.h"
#include "Controller.h"
#include "Player.h"
#include "TypeWrite.h"
#include "Platform.h"

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
	mitoHouse.setPath("Content/WhaleIsland/mitos_house.json");

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

	if (!bounds) {
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

void Map::drawPaths(std::vector<std::string>& canvas, Area& area, gridBoundaries boundaries, int cellWidth) {
	std::vector<Location>& locations = area.getLocations();

	for (const Location& location : locations) {
		if (location.isBorder()) {
			continue;
		}
		Location::Coordinates position = location.getCoordinates();
		std::vector<Location*> neighbors = location.getNeighbors();
		int column = (position.x - boundaries.minimum.x) * cellWidth;
		int row = (boundaries.maximum.y - position.y) * 8;
		for (const Location* neighbor : neighbors) {
			Location::Coordinates neighborPosition = neighbor->getCoordinates();
			int neighborColumn = (neighborPosition.x - boundaries.minimum.x) * cellWidth;
			int neighborRow = (boundaries.maximum.y - neighborPosition.y) * 8;

			bool vertical = (column == neighborColumn && row != neighborRow);
			bool horizontal = (column != neighborColumn && row == neighborRow);
			bool diagonal = (column != neighborColumn && row != neighborRow);

			if (vertical) {
				int startRow = std::min(row, neighborRow) + 1;
				int endRow = std::max(row, neighborRow);
				for (int i = startRow; i < endRow; i++) {
					canvas[i][column] = '|';
				}
			}
			if (horizontal) {
				int startColumn = std::min(column, neighborColumn) + 1;
				int endColumn = std::max(column, neighborColumn);
				for (int i = startColumn; i < endColumn; i++) {
					canvas[row][i] = '-';
				}
			}
			if (diagonal) {
				int startColumn = std::min(column, neighborColumn) + 1;
				int endColumn = std::max(column, neighborColumn);
				double slope = static_cast<double> (neighborRow - row) / (neighborColumn - column);
				int lastRow = -1;

				for (int i = startColumn; i < endColumn; i++) {
					int pathRow = row + static_cast<int>(std::round((i - column) * slope));
					if (pathRow != lastRow) {
						canvas[pathRow][i] = slope > 0 ? '*' : '/' + '/';
						lastRow = pathRow;
					}
				}
			}
		}
	}
}

void Map::drawLocations(std::vector<std::string>& canvas, Area& area, gridBoundaries boundaries, int cellWidth) {
	std::vector<Location>& locations = area.getLocations();

	for (Location& location : locations) {
		if (location.isBorder()) {
			continue;
		}
		else {
			Location::Coordinates position = location.getCoordinates();
			int column = (position.x - boundaries.minimum.x) * cellWidth;
			int row = (boundaries.maximum.y - position.y) * 8;
			std::string name = location.getName();
			for (std::size_t i = 0; i < name.size(); i++) {
				canvas[row][column + i] = name[i];
			}
		}
	}
}

void Map::displayMap(Player& player) {
	Area* currentArea = player.getCurrentArea(player.getCurrentLocation());
	bool viewingMap = true;
	std::string mapTitle = "    ======== Map ========";
	while (viewingMap) {
		int screenWidth = Platform::getScreenWidth();
		std::string areaTitle = "  ====== " + currentArea->name + " ======  ";
		clearScreen();
		typeWrite(mapTitle);
		typeWrite(areaTitle);
		if (currentArea->getLocations().empty()) {
			std::cout << "Empty Area" << std::endl;
		}
		else {
			size_t longestNameLength = 0;
			std::vector<Location>& locations = currentArea->getLocations();
			for (const Location& location : locations) {
				size_t length = location.getName().size();
				if (length > longestNameLength) {
					longestNameLength = length;
				}
			}
			gridBoundaries boundaries = getGridBoundaries(*currentArea);
			int height = (boundaries.maximum.y - boundaries.minimum.y) * 8 + 1;
			int usableWidth = boundaries.maximum.x - boundaries.minimum.x;
			if (usableWidth == 0) {
				std::cout << "terminal too small" << std::endl;
			}
			int cellWidth = (screenWidth - static_cast<int>(longestNameLength)) / usableWidth;
			int width = usableWidth * cellWidth + static_cast<int>(longestNameLength);
			std::vector<std::string> mapCanvas = canvas(width, height);
			drawPaths(mapCanvas, *currentArea, boundaries, cellWidth);
			drawLocations(mapCanvas, *currentArea, boundaries, cellWidth);
			for (const std::string& line : mapCanvas) {
				std::cout << line << std::endl;
			}
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