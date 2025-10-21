#include <string>
#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	~Zombie();
	Zombie(std::string name);
	void announce(void);
	void randomChump(std::string name);
};

Zombie* zombieHorde(int N, std::string name);