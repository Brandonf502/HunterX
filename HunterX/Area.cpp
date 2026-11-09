#include "Area.h"

Area::Area(const std::string& areaName) : name(areaName) {}

std::vector<Location>& Area::getLocations() {
    return this->locations;
}