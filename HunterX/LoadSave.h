#pragma once

#include <vector>
#include <string>

struct savedStates {
	std::string playerName;
	int currentHealth;
};

std::vector<savedStates> loadSavedGames();
int chooseSavedGames(const std::vector<savedStates>& savedGames);