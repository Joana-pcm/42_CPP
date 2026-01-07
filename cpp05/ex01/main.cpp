#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{       
    Bureaucrat b1("Alice", 2);
    Form f1("TopSecret", 1, 1, false);

    std::cout << b1 << std::endl;
    std::cout << "Before signing:" << std::endl;
    std::cout << f1 << std::endl;
    try {
        f1.beSigned(b1);
        std::cout << "After signing:" << std::endl;
        std::cout << f1 << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}