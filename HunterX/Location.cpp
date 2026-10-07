#include "Location.h"


Location::Location(const std::string& locationName) : name(locationName) {}

std::string Location::getName() const {
	return name;
}

Area* Location::getArea() const {
	return area;
}

void Location::setArea(Area* locationArea) {
	area = locationArea;
}

