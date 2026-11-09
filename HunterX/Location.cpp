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

Location* Location::getNorth() const {
	return this->north;
}

Location* Location::getEast() const {
	return this->east;
}

Location* Location::getSouth() const {
	return this->south;
}

Location* Location::getWest() const {
	return this->west;
}

void Location::setNorth(Location* location = nullptr) {
	this->north = location;
}

void Location::setEast(Location* location = nullptr) {
	this->east = location;
}

void Location::setSouth(Location* location = nullptr) {
	this->south = location;
}

void Location::setWest(Location* location = nullptr) {
	this->west = location;
}

void Location::setCoordinates(Coordinates coordinates) {
	this->position = coordinates;
}

Location::Coordinates Location::getCoordinates() const {
	return this->position;
}

bool Location::isBorder() const{
	if (
		this->getNorth() == nullptr &&
		this->getEast() == nullptr &&
		this->getSouth() == nullptr &&
		this->getWest() == nullptr
		) {
		return true;
	}
	return false;
}
