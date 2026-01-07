#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("John"), grade(150)
{
    std::cout << "Default Bureaucrat constructed." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructed." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade < 1) {
        std::cout << "Error constructing Bureaucrat " << name << ": ";
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150)
    {
        std::cout << "Error constructing Bureaucrat " << name << ": ";
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade = grade;
    std::cout << "Bureaucrat constructed." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade)
{
    std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
        this->grade = src.grade;
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
    {
        std::cout << "Error incrementing " << this->name << "'s grade: ";
        throw Bureaucrat::GradeTooHighException();
    }    
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150)
    {
        std::cout << "Error decrementing " << this->name << "'s grade: ";
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
}
void Bureaucrat::signForm(const Form &form)
{
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return (out);
}