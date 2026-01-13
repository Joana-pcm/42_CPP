#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

class PresidentialPardonForm : public AForm
{
private:
	std::string target;	

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();
	void execute(const Bureaucrat &executor) const;
};