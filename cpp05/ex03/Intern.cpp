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
	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (Intern::*functions[3])(const std::string) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
			return (this->*functions[i])(target);
	}
	throw FormException();
}

AForm *Intern::createShrubbery(const std::string target)
{
	std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomy(const std::string target)
{
	std::cout << "Intern creates RobotomyRequestForm" << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidential(const std::string target)
{
	std::cout << "Intern creates PresidentialPardonForm" << std::endl;
	return (new PresidentialPardonForm(target));
}

const char *Intern::FormException::what() const throw()
{
	return ("Form name doesn't exist.");
}