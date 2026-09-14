#pragma once

#include <string>
#include <vector>

class Player {
private:
	int health;
	std::string name;
	std::vector <std::string> inventory;

public:
	Player();
	Player(const std::string& playerName);

	std::string getName() const;
	int getHealth() const;
};