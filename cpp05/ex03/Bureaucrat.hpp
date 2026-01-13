#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        void signForm(AForm *form);
        void executeForm(const AForm &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);