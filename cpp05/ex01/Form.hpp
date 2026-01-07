#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool signature;
	const int gradeSign;
	const int gradeExecute;

public:
	Form();
	~Form();
	Form(const std::string name, const int gradeS, const int gradeE, bool sign);
	Form(const Form &other);
	void beSigned(const Bureaucrat &b);
	const std::string getName() const;
	bool getSignature() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Form &f);