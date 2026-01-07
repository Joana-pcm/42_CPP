#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1;
        std::cout << b1 << std::endl;

        for (int i = 0; i < 150; i++)
            b1.decrementGrade();
        std::cout << b1 << std::endl;

        b1.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
    }

    try
    {
        Bureaucrat b2("Alice", 1);
        std::cout << b2 << std::endl;

        b2.incrementGrade();
        std::cout << b2 << std::endl;
    }

    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
    }

    try
    {
        Bureaucrat b3("Bob", 151);
        std::cout << b3 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
    }

    return 0;
}