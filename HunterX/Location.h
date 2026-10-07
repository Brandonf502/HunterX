#pragma once
#include <iostream>


class Area;
class Location {
private:
	std::string name;
	Area* area = nullptr;

public:
	Location* north = nullptr;
	Location* south = nullptr;
	Location* east = nullptr;
	Location* west = nullptr;
	

	Location(const std::string& locationName);
	std::string getName() const;
	Area* getArea() const;
	void setArea(Area* locationArea);

	
};


