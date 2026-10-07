#pragma once

#include <string>
#include <vector>
#include "Location.h"
#include "Area.h"

class Location;
class Area;
class Player {
private:
	int health;
	std::string name;
	std::vector <std::string> inventory;
	Location* currentLocation;
	Area* currentArea;

public:
	Player();
	Player(const std::string& playerName);
	void setCurrentLocation(Location* location);
	Location* getCurrentLocation() const;
	Area* getCurrentArea(Location* location);
	std::string getName() const;
	int getHealth() const;
};