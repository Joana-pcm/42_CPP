#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("John"), grade(150)
{
    std::cout << "Bureaucrat constructed." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructed." << std::endl;
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

void Bureaucrat::GradeTooHighException()
{
    throw std::out_of_range("Grade too high");
}

void Bureaucrat::GradeTooLowException()
{
    throw std::out_of_range("Grade too low");
}

void Bureaucrat::rangeGrade()
{
    std::out_of_range e("Grade out of range");
    try {
        if (this->grade < 1)
            Bureaucrat::GradeTooHighException();
        else if (this->grade > 150)
            Bureaucrat::GradeTooLowException();
    }
    catch (const std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Bureaucrat::incrementGrade()
{
    if (this->grade <= 1)
        Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade >= 150)
        Bureaucrat::GradeTooLowException();
    this->grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return (out);
}