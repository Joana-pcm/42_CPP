#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5, false), target("Default")
{
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", 25, 5, false), target(target)
{
	std::cout << "PresidentialPardonForm Parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), target(other.target)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getSignature() == false)
	{
		std::cout << "Form " << this->getName() << " is not signed yet." << std::endl;
		throw AForm::GradeTooLowException();
	}
	else if (executor.getGrade() > this->getGradeExecute())
	{
		std::cout << executor.getName() << " couldn't execute " << this->getName() << std::endl;
		throw AForm::GradeTooLowException();
	}
	else
	{
		std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}