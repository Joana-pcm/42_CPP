#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

class Base
{
public:
	virtual ~Base() {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base* generate();
void identify(Base* p);
void identify(Base& p);