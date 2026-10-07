#include "Map.h"
#include "Location.h"
#include "Area.h"

void Map::buildMap() {

	areas.reserve(3);
	areas.emplace_back("Whale Island");
	Area& whaleIsland = areas.back();
	whaleIsland.locations.reserve(13);

	whaleIsland.locations.emplace_back("Forest");
	whaleIsland.locations.emplace_back("West Forest");
	whaleIsland.locations.emplace_back("East Forest");
	whaleIsland.locations.emplace_back("South Forest");
	whaleIsland.locations.emplace_back("Mito's House");
	whaleIsland.locations.emplace_back("Swamp");
	whaleIsland.locations.emplace_back("River");
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
	Location& river = whaleIsland.locations[6];
	Location& portTown = whaleIsland.locations[7];
	Location& portDock = whaleIsland.locations[8];
	Location& northBorder = whaleIsland.locations[9];
	Location& eastBorder = whaleIsland.locations[10];
	Location& southBorder = whaleIsland.locations[11];
	Location& westBorder = whaleIsland.locations[12];

	northBorder.setArea(&whaleIsland);
	eastBorder.setArea(&whaleIsland);
	southBorder.setArea(&whaleIsland);
	westBorder.setArea(&whaleIsland);

	Forest.north = &mitoHouse;
	Forest.east = &swamp;
	Forest.south = &portTown;
	Forest.west = &river;
	Forest.setArea(&whaleIsland);

	eastForest.north = &northBorder;
	eastForest.east = &eastBorder;
	eastForest.south = &swamp;
	eastForest.west = &mitoHouse;
	eastForest.setArea(&whaleIsland);

	westForest.north = &northBorder;
	westForest.east = &river;
	westForest.south = &portTown;
	westForest.west = &westBorder;
	westForest.setArea(&whaleIsland);

	mitoHouse.north = &northBorder;
	mitoHouse.east = &eastForest;
	mitoHouse.south = &Forest;
	mitoHouse.west = &river;
	mitoHouse.setArea(&whaleIsland);

	portTown.north = &Forest;
	portTown.east = &southForest;
	portTown.south = &portDock;
	portTown.west = &river;
	portTown.setArea(&whaleIsland);

	portDock.north = &portTown;
	portDock.east = &eastBorder;
	portDock.south = &southBorder;
	portDock.west = &westBorder;
	portDock.setArea(&whaleIsland);
	

	swamp.north = &eastForest;
	swamp.east = &eastBorder;
	swamp.south = &portTown;
	swamp.west = &Forest;
	swamp.setArea(&whaleIsland);

	river.north = &mitoHouse;
	river.east = &Forest;
	river.south = &portTown;
	river.west = &westForest;
	river.setArea(&whaleIsland);

	this->northBorder = &northBorder;
	this->eastBorder = &eastBorder;
	this->southBorder = &southBorder;
	this->westBorder = &westBorder;
	

	this->first = &areas[0];
}

Location* Map::getStartingLocation() {
	return &areas[0].locations[4];
}