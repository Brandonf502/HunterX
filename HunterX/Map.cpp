#include "Map.h"
#include "Location.h"
#include "Area.h"

void Map::buildMap() {

	areas.reserve(3);
	areas.emplace_back("Whale Island");
	Area& whaleIsland = areas.back();
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

	westForest.north = &northRiver;
	westForest.east = &river;
	westForest.south = &southRiver;;
	westForest.west = &westBorder;
	westForest.setArea(&whaleIsland);

	southForest.north = &swamp;
	southForest.east = &eastBorder;
	southForest.south = &southBorder;
	southForest.west = &portTown;
	southForest.setArea(&whaleIsland);

	mitoHouse.north = &northBorder;
	mitoHouse.east = &eastForest;
	mitoHouse.south = &Forest;
	mitoHouse.west = &northRiver;
	mitoHouse.setArea(&whaleIsland);

	portTown.north = &Forest;
	portTown.east = &southForest;
	portTown.south = &portDock;
	portTown.west = &southRiver;
	portTown.setArea(&whaleIsland);

	portDock.north = &portTown;
	portDock.east = &eastBorder;
	portDock.south = &southBorder;
	portDock.west = &westBorder;
	portDock.setArea(&whaleIsland);
	

	swamp.north = &eastForest;
	swamp.east = &eastBorder;
	swamp.south = &southForest;
	swamp.west = &Forest;
	swamp.setArea(&whaleIsland);

	northRiver.north = &northBorder;
	northRiver.east = &mitoHouse;
	northRiver.south = &river;
	northRiver.west = &westForest;
	northRiver.setArea(&whaleIsland);

	river.north = &northRiver;
	river.east = &Forest;
	river.south = &southRiver;
	river.west = &westForest;
	river.setArea(&whaleIsland);

	southRiver.north = &river;
	southRiver.east = &portTown;
	southRiver.south = &southBorder;
	southRiver.west = &westForest;
	southRiver.setArea(&whaleIsland);

	this->northBorder = &northBorder;
	this->eastBorder = &eastBorder;
	this->southBorder = &southBorder;
	this->westBorder = &westBorder;
	

	this->first = &areas[0];
}

Location* Map::getStartingLocation() {
	return &areas[0].locations[4];
}