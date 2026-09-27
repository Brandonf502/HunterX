#pragma once

enum class Action {
	North, East, South, West,
	Inventory, Menu, Exit, Number, Map, None
};

struct Input {
	Action action = Action::None;
	int number = 0;
};

class Controller {
public:
	Input readAction();
};

