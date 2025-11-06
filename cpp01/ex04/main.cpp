#include "Sed.hpp"

int main(int ac, char** av)
{
	if (ac != 4)
		return (0);
	Sed sed(av[1]);
	sed.replaceInFile(av[2], av[3]);
	return 0;
}