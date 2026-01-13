#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool signature;
	const int gradeSign;
	const int gradeExecute;

public:
	AForm();
	virtual ~AForm() = 0;
	AForm(const std::string name, const int gradeS, const int gradeE, bool sign);
	AForm(const AForm &other);
	void beSigned(const Bureaucrat &b);
	const std::string getName() const;
	bool getSignature() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	virtual void execute(const Bureaucrat &executor) const = 0;
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &f);