#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructed." << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern Copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
	int	i = -1;
	AForm *form;

	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	while (++i < 3)
	{
		if (formNames[i] == formName)
			break;
	}
	switch (i) {
		case 0:
		form = new ShrubberyCreationForm(target);
		break;
		case 1:
		form = new RobotomyRequestForm(target);
		break;
		case 2:
		form = new PresidentialPardonForm(target);
		break;
		default:
		throw FormException();
	}
	return (form);
}

const char *Intern::FormException::what() const throw()
{
	return ("Form name doesn't exist.");
}