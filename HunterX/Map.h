#pragma once
#include <iostream>
#include <vector>
#include "Area.h"
#include "Location.h"


class Map {
private:
	std::string worldMap = "World Map";
	std::vector<Area> areas;
	Location* northBorder = nullptr;
	Location* eastBorder = nullptr;
	Location* southBorder = nullptr;
	Location* westBorder = nullptr;
	Area* first = nullptr;
	Area* last = nullptr;

public: 
	Location* getStartingLocation();
	void buildMap();
	
};