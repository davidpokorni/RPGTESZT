#include <iostream>
#include <string>
#include "character.h"

int main() {
	using std::stoi;
	using std::cout;
	try {
		Character player("name",5,6);
		Character enemy("name",5,6);
		while (enemy.isAlive() && player.isAlive()) {
			player.attack(enemy);
			cout << player;
			cout << enemy;
			// Enemy dead
			if (!enemy.isAlive()) {
				cout << enemy.getName() << " died. " << player.getName() << " wins.\n";
				break;
			}
			enemy.attack(player);
			cout << player;
			cout << enemy;
			// Player dead
			if (!player.isAlive()) {
				cout << player.getName() << " died. " << enemy.getName() << " wins.\n";
			}
		}
	}
	catch (std::invalid_argument &ia) {
		std::cerr << "Invalid argument\n";
	}
	return 0;
} 