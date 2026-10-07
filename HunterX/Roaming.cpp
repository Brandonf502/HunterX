#include "Roaming.h"
#include "TypeWrite.h"
#include "Controller.h"

void AreaState::roam() {
	switch (currentArea) {
	case Roaming::WhaleIsland: {
		typeWrite("You are in Whale Island.\n");
		Input input = Controller().readAction();
		break;
	}
	case Roaming::HeavensArena: {
		typeWrite("You are in Heavens Arena.\n");
		Input input = Controller().readAction();
		break;
	}
	case Roaming::GreedIsland: {
		typeWrite("You are in Greed Island.\n");
		Input input = Controller().readAction();
		break;
	}
	}
}