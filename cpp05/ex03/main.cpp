#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		std::cout << "------ Failed Tests ------" << std::endl << std::endl;
		
	}
	{
		std::cout << "------ Successful Test ------" << std::endl << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		
	}
    return 0;
}