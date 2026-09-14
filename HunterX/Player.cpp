#include "Player.h"


Player::Player()
	: name(""),
	health(100)
{
}

Player::Player(const std::string& playerName) {
	
	name = playerName;
	health = 100;
	 

}

std::string Player::getName() const {
	return name;
}

int Player::getHealth() const {
	return health;
}
