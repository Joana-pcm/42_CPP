#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void GradeTooHighException();
        void GradeTooLowException();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);