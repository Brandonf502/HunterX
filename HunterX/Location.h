#pragma once
#include <iostream>

class Location {
private:
	std::string name;
public:
	Location* north = nullptr;
	Location* south = nullptr;
	Location* east = nullptr;
	Location* west = nullptr;
	

	Location(const std::string& locationName);
	std::string getName() const;
	
};


