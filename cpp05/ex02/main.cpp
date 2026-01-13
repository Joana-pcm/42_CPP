#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		std::cout << "------ Failed Tests ------" << std::endl << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Abilio", 150);
		std::cout << *bureaucrat << std::endl;
		ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");
        std::cout << std::endl << "===========\n" << *shrubbery
        << "===========\n" << std::endl;
		bureaucrat->signForm(shrubbery);
		bureaucrat->executeForm(*shrubbery);
		RobotomyRequestForm *robotomy = new RobotomyRequestForm("Home");
		std::cout << std::endl << "===========\n" << *robotomy
        << "===========\n" << std::endl;
		bureaucrat->signForm(robotomy);
		bureaucrat->executeForm(*robotomy);
		PresidentialPardonForm *presidential = new PresidentialPardonForm("Home");
		std::cout << std::endl << "===========\n" << *presidential
        << "===========\n" << std::endl;
		bureaucrat->signForm(presidential);
		bureaucrat->executeForm(*presidential);
        std::cout << std::endl << "------ Destroying Forms... ------" << std::endl;
		delete bureaucrat;
		delete shrubbery;
		delete robotomy;
		delete presidential;
		std::cout << std::endl << std::endl;
	}
	{
		std::cout << "------ Successful Test ------" << std::endl << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Josephine", 1);
		std::cout << *bureaucrat << std::endl;
		ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");
		std::cout << std::endl << "===========\n" << *shrubbery 
        << "===========\n" << std::endl;
		bureaucrat->signForm(shrubbery);
		bureaucrat->executeForm(*shrubbery);
		std::cout << std::endl << "===========\n" << *shrubbery
        << "===========\n" << std::endl;
		RobotomyRequestForm *robotomy = new RobotomyRequestForm("Robocop");
		std::cout << *robotomy << std::endl;
		bureaucrat->signForm(robotomy);
		bureaucrat->executeForm(*robotomy);
		std::cout << std::endl << "===========\n" << *robotomy
        << "===========" << std::endl;
		PresidentialPardonForm *presidential = new PresidentialPardonForm("Emilio");
		std::cout << std::endl << "===========\n" << *presidential
        << "===========\n" << std::endl;
		bureaucrat->signForm(presidential);
		bureaucrat->executeForm(*presidential);
		std::cout << std::endl << "===========\n" << *presidential
        << "===========\n" << std::endl;
        std::cout << std::endl << "------ Destroying Forms... ------" << std::endl;
		delete bureaucrat;
		delete shrubbery;
		delete robotomy;
		delete presidential;
		std::cout << std::endl;
	}
    return 0;
}