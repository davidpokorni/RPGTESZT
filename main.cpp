#include <iostream>
#include <string>
#include "character.h"
using namespace std;
int main(int argc, char* argv[]) {
	//using std::stoi;
	
	try {
		//Character player = Character::parseUnit("fighter.json");
		//Character enemy = Character::parseUnit("enemy.json");
		Character player = Character("name",5,6);
		Character enemy=Character("name",5,6);
		while (enemy.isAlive() && player.isAlive()) {
			player.attack(enemy);
			// Enemy dead
			if (!enemy.isAlive()) {
				cout << player.getName() << " wins. Remaining HP: " << player.getHp() << std::endl;
				break;
			}
			enemy.attack(player);
			// Player dead
			if (!player.isAlive()) {
				cout << enemy.getName() << " wins. Remaining HP: " << enemy.getHp() << std::endl;
			}
		}
	}
	catch (std::invalid_argument &ia) {
		std::cerr << "Invalid argument\n";
	}
	return 0;
}