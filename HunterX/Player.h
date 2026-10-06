#pragma once

#include <string>
#include <vector>

class Location;
class Player {
private:
	int health;
	std::string name;
	std::vector <std::string> inventory;
	Location* currentLocation;

public:
	Player();
	Player(const std::string& playerName);
	void setCurrentLocation(Location* location);
	Location* getCurrentLocation() const;
	std::string getName() const;
	int getHealth() const;
};