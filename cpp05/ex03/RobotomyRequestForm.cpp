#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45, false), target("Default")
{
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
	srand(static_cast<unsigned int>(time(0)));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45, false), target(target)
{
	std::cout << "RobotomyRequestForm Parameterized constructor called" << std::endl;
	srand(static_cast<unsigned int>(time(0)));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target(other.target)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getSignature() == false)
	{
		std::cout << "Form " << this->getName() << " is not signed yet." << std::endl;
		throw AForm::GradeTooLowException();
	}
	else if (executor.getGrade() > this->getGradeExecute())
	{
		std::cout << executor.getName() << " can't execute " << this->getName() << std::endl;
		throw AForm::GradeTooLowException();
	}
	else
	{
		std::cout << "Brrrrrrr... Brrrrrrr... *drilling noises*" << std::endl;
		if (rand() % 2 == 0)
			std::cout << target << " has been robotomized successfully." << std::endl;
		else
			std::cout << "Robotomy failed on " << target << "." << std::endl;
	}
}