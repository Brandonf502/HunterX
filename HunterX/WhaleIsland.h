#pragma once
#include "Area.h"
#include "Player.h"
#include "Controller.h"

class WhaleIsland {
public:
	WhaleIsland(Area* whaleIslandArea);
	void movement(Player& player, Input& input);
	std::string locationName(Player& player);
	
private:
	Area* area = nullptr;
};