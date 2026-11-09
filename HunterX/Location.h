#pragma once
#include <iostream>


class Area;
class Location {
public:
	Location(const std::string& locationName);
	[[nodiscard]] std::string getName() const;
	[[nodiscard]] Area* getArea() const;
	void setArea(Area* locationArea);
	struct Coordinates {
		int x;
		int y;
	};
	[[nodiscard]] Location* getNorth() const;
	[[nodiscard]] Location* getEast() const;
	[[nodiscard]] Location* getSouth() const;
	[[nodiscard]] Location* getWest() const;
	void setNorth(Location* location);
	void setEast(Location* location);
	void setSouth(Location* location);
	void setWest(Location* location);
	[[nodiscard]] Coordinates getCoordinates() const;
	void setCoordinates(Coordinates coordinates);
	bool isBorder() const;

private:
	std::string name;
	Area* area = nullptr;
	Coordinates position;
	Location* north = nullptr;
	Location* south = nullptr;
	Location* east = nullptr;
	Location* west = nullptr;
	bool border = false;
};


