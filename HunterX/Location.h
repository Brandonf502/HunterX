#pragma once
#include <iostream>

class Location {
public:
	std::string name;
	Location* north = nullptr;
	Location* south = nullptr;
	Location* east = nullptr;
	Location* west = nullptr;

	Location(const std::string& locationName);
	
};


