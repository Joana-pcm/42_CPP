#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137, false), target("Default")
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", 145, 137, false), target(target)
{
	std::cout << "ShrubberyCreationForm Parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
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
		std::ofstream outfile((target + "_shrubbery").c_str());
		if (!outfile)
		{
			std::cerr << "Error creating file: " << target + "_shrubbery" << std::endl;
			return;
		}
		outfile << "       _-_\n"
				   "    /~~   ~~\\\n"
				   " /~~         ~~\\\n"
				   "{               }\n"
				   " \\  _-     -_  /\n"
				   "   ~  \\\\ //  ~\n"
				   "_- -   | | _- _\n"
				   "  _ -  | |   -_\n"
				   "      // \\\\\n";
		outfile.close();
		std::cout << executor.getName() << " executed " << this->getName() << " and created " << target + "_shrubbery" << std::endl;
	}
}