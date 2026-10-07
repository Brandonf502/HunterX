#pragma once

enum class Roaming {
	WhaleIsland,
	HeavensArena,
	GreedIsland,
};

struct AreaState {
	Roaming currentArea;
	void roam();
};
