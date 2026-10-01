#pragma once
#include <iostream>
#include <vector>

class Map {
	std::string worldMap = "World Map";
	std::vector<Area> areas;
	Location* northBorder = nullptr;
	Location* eastBorder = nullptr;
	Location* southBorder = nullptr;
	Location* westBorder = nullptr;
	Area* first = nullptr;
	Area* last = nullptr;
	 
	static Map buildMap();
	
};