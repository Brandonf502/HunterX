#pragma once
#include "PlayerRequest.h"

enum class Roaming {
	WhaleIsland,
	HeavensArena,
	GreedIsland,
};

class Player;
struct AreaState {
	Roaming currentArea;
	PlayerRequest playerRequest = PlayerRequest::None;
	void roam(Player& player);
};
