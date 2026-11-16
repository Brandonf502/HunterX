#pragma once
#include "Area.h"
#include "Player.h"
#include "Controller.h"
#include "ContentNodeTree.h"

class WhaleIsland {
public:
	WhaleIsland(Area* whaleIslandArea);
	Location* movement(Player& player, Input& input);
	std::string locationName(Player& player);
	void displayContent(Player& player);
	
private:
	Area* area = nullptr;
	ContentNodeTree whaleIslandTree;

};