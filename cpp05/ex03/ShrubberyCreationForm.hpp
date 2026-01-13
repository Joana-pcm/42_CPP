#pragma once
#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();
	void execute(const Bureaucrat &executor) const;
};