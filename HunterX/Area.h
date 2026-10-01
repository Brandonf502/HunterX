#pragma once
#include "Location.h"
#include <iostream>
#include <vector>

class Area {
public:
	std::string name;
	std::vector<Location> locations;
	Area* next = nullptr;
	Area* previous = nullptr;

	Area(const std::string& areaName);
};