#pragma once
#include <iostream>
#include <vector>
#include "Area.h"
#include "Location.h"
#include "Player.h"
#include "Controller.h"

class Player;
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
	struct gridBoundaries {
		Location::Coordinates minimum;
		Location::Coordinates maximum;
	};
	gridBoundaries getGridBoundaries(Area& area);
	std::vector<std::string> canvas(int width, int height);
	void drawLocations(std::vector<std::string>& canvas, Area& area, gridBoundaries boundaries);


public: 
	Location* getStartingLocation();
	void buildMap();
	void displayMap(Player& player);



	
};