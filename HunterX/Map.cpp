#include "Map.h"
#include "Location.h"
#include "Area.h"

Map Map::buildMap() {

	Area whaleIsland("Whale Island");

	Location Forest("Forest");
	Location mitoHouse("Mito's House");
	Location swamp("Swamp");
	Location river("River");
	Location portTown("Port Town");
	Location portDock("Port Dock");
	Location northBorder("North");
	Location eastBorder("East");
	Location southBorder("South");
	Location westBorder("West");

	whaleIsland.locations.push_back(Forest);
	whaleIsland.locations.push_back(mitoHouse);
	whaleIsland.locations.push_back(swamp);
	whaleIsland.locations.push_back(river);
	whaleIsland.locations.push_back(portTown);
	whaleIsland.locations.push_back(portDock);
	whaleIsland.locations.push_back(northBorder);
	whaleIsland.locations.push_back(eastBorder);
	whaleIsland.locations.push_back(southBorder);
	whaleIsland.locations.push_back(westBorder);

	Forest.north = &mitoHouse;
	Forest.east = &swamp;
	Forest.south = &portTown;
	Forest.west = &river;

	mitoHouse.north = &northBorder;
	mitoHouse.east = &eastBorder;
	mitoHouse.south = &Forest;
	mitoHouse.west = &river;

	portTown.north = &Forest;
	portTown.east = &Forest;
	portTown.south = &portDock;
	portTown.west = &river;

	portDock.north = &portTown;
	portDock.east = &eastBorder;
	portDock.south = &southBorder;
	portDock.west = &westBorder;

	swamp.north = &northBorder;
	swamp.east = &eastBorder;
	swamp.south = &Forest;
	swamp.west = &Forest;




	Map map;

	map.northBorder = &northBorder;
	map.eastBorder = &eastBorder;
	map.southBorder = &southBorder;
	map.westBorder = &westBorder;
	map.areas.push_back(whaleIsland);

	map.first = &whaleIsland;
	







}