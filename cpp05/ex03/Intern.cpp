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
	std::cout << "Intern Destructor called" << std::endl;
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
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	std::cout << "\n------ Forms' Constructors ------ " << std::endl;
	AForm *forms[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	std::cout << "---------------------------------\n" << std::endl;

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << " form." << std::endl;
			std::cout << "\n------ Destructors ------ " << std::endl;
			for (int j = 0; j < 3; j++)
			{
				if (j != i)
					delete forms[j];
			}
			std::cout << "-------------------------\n" << std::endl;
			return (forms[i]);
		}
	}
	std::cout << "Intern could not find the form: " << formName << std::endl;
	std::cout << "------ Destructors ------ " << std::endl;
	for (int j = 0; j < 3; j++)
	{
		delete forms[j];
	}
	return (NULL);
}