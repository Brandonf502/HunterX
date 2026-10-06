#pragma once

#include "GameState.h"
#include "Player.h"
#include "Map.h"

class PlayGame {

private:
	GameState state;
	Player player;
	Map map;
public:
	void gameOn();

};

