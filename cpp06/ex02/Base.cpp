#include "Base.hpp"

Base* generate()
{
	int randNum = std::rand() % 4;
	switch (randNum)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	default:
		return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "NULL" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception& e){}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "B" << std::endl;
	}
	catch (const std::exception& e) {}
	try 
	{
		C& c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "C" << std::endl;
	}
	catch (const std::exception& e) {}
}

