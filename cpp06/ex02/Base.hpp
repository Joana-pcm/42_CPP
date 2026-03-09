#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
public:
	virtual ~Base() {};
};

class A : public Base {
	public:
	A():Base(){};
	~A(){};
};

class B : public Base {
	public:
	B():Base(){};
	~B(){};
};

class C : public Base {
	public:
	C():Base(){};
	~C(){};
};

Base* generate();
void identify(Base* p);
void identify(Base& p);