#include "character.h"
#include <iostream>
#include <fstream>

Character::Character(const std::string name, int hp, int dmg) : name(name)
{
	this->hp = hp;
	this->dmg = dmg;
}

std::string Character::getName() const
{
	return name;
}

int Character::getHp() const
{
	return hp;
}

int Character::getDmg() const
{
	return dmg;
}

bool Character::isAlive() const
{
	if (this->getHp() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Character::attack(Character &c)
{
	if (c.isAlive())
	{
		c.hp = (c.hp - this->getDmg()) > 0 ? c.hp - this->getDmg() : 0;
	}
}

std::ostream & operator<<(std::ostream & os, const Character &C)
{
	os << C.getName() << ": HP: " << C.getHp() << ", DMG: " << C.getDmg() << '\n';
	return os;
}

Character Character::parseUnit(std::string charSheetName)
{
	std::fstream charSheet(charSheetName);

	if (charSheet.fail())
	{
		std::string error("Couldn't open file");
		throw std::runtime_error(error);
	}

	std::string name = "";
	int hp = 0;
	int dmg = 0;

	std::string line;

	while (!charSheet.eof())
	{
		std::getline(charSheet, line);

		if (name == "")
		{
			std::string s = "name";
			if (line.find(s) != std::string::npos) {
				int end = line.rfind('"');
				int start = end;
				bool find = true;
				while (find)
				{
					start--;
					if (line[start] == '"')
					{
						find = false;
					}
				}
				int length = end - start - 1;
				name = line.substr(start + 1, length);
			}
		}

		if (hp == 0)
		{
			std::string s = "hp";
			if (line.find(s) != std::string::npos) {
				int start = line.rfind(':');
				int end = line.rfind(',');
				int length = end - start - 2;
				hp = std::stoi(line.substr(start + 2, length));
			}
		}

		if (dmg == 0)
		{
			std::string s = "dmg";
			if (line.find(s) != std::string::npos) {
				int start = line.rfind(':');
				int length = line.length() - start - 1;
				dmg = std::stoi(line.substr(start + 2, length));
			}
		}
	}
	charSheet.close();
	return Character(name, hp, dmg);
}