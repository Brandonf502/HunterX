#include "Location.h"

Location::Location(const std::string& locationName) : name(locationName) {}

std::string Location::getName() const {
	return name;
}

