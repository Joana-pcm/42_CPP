#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	AForm *makeForm(const std::string formName, const std::string target);
	class FormException : public std::exception
	{
		public:
            const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Intern &i);