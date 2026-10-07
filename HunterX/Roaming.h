#pragma once

enum class Roaming {
	WhaleIsland,
	HeavensArena,
	GreedIsland,
};

class Player;
struct AreaState {
	Roaming currentArea;
	void roam(Player& player);
};
