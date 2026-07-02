#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cstdlib>

class RPN
{
private:
	std::stack<int> _stack;
public:
	RPN();
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);

	void evaluate(const std::string &expression);
	int getResult() const;
};