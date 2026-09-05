#include <string>
#include <vector>

class Player {
private:
	int health;
	std::string name;
	std::vector <std::string> inventory;

public:
	Player(const std::string& playerName);

};