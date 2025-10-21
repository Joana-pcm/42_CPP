#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "HumanB.hpp"

class Weapon {
	private:
	std::string type;

	public:
	Weapon();
	Weapon(std::string type);
	~Weapon();

	const std::string &getType();
	void setType(std::string type);
};