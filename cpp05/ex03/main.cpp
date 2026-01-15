#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		std::cout << "------ Failed Tests ------\n" << std::endl;
		std::cout << "----------------------\n";
		std::cout << "Creating a form that doesn't exist:\n" << std::endl;
		Intern someRandomIntern;
		AForm *random;
		try
		{
			random = someRandomIntern.makeForm("random", "Bender");
			std::cout << *random << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "----------------------\n";
		std::cout << std::endl << "Attempting to sign and execute with low grade bureaucrat:\n" << std::endl;
		AForm *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		Bureaucrat *b1 = new Bureaucrat("Bureaucrat 1", 150);
		std::cout << *b1 << std::endl;
		b1->signForm(rrf);
		Bureaucrat *b2 = new Bureaucrat("Bureaucrat 2", 50);
		std::cout << *b2 << std::endl;
		b2->signForm(rrf);
		b2->executeForm(*rrf);
		std::cout << std::endl << "----------------------\n";
		std::cout << "------ Destructors... ------" << std::endl;
		delete b1;
		delete b2;
		delete rrf;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << "------ Successful Tests ------\n" << std::endl;
		std::cout << "----------------------\n";
		std::cout << "------ Constructors ------\n" << std::endl;
		Intern someRandomIntern;
		AForm *rrf;
		AForm *scf;
		AForm *ppf;
		std::cout << "----------------------\n";
		std::cout << "Creating forms through Intern:\n" << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *rrf << std::endl;
		std::cout << *scf << std::endl;
		std::cout << *ppf << std::endl;
		std::cout << "----------------------\n";
		std::cout << "Signing and executing forms with high grade bureaucrat:\n" << std::endl;
		Bureaucrat *b1 = new Bureaucrat("Bureaucrat 1", 150);
		std::cout << *b1 << std::endl;
		b1->signForm(rrf);
		b1->signForm(scf);
		b1->signForm(ppf);
		Bureaucrat *b2 = new Bureaucrat("Bureaucrat 2", 5);
		std::cout << *b2 << std::endl;
		b2->signForm(rrf);
		b2->signForm(scf);
		b2->signForm(ppf);
		b2->executeForm(*rrf);
		b2->executeForm(*scf);
		b2->executeForm(*ppf);
		std::cout << std::endl << "----------------------\n";
		std::cout << "------ Destructors... ------" << std::endl;
		delete b1;
		delete b2;
		delete rrf;
		delete scf;
		delete ppf;
	}
    return 0;
}