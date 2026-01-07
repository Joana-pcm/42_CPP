#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), signature(false), gradeSign(150), gradeExecute(150)
{
	std::cout << "Form Default constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const Form &other)
	: name(other.name), signature(other.signature), gradeSign(other.gradeSign), gradeExecute(other.gradeExecute)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

Form::Form(const std::string name, const int gradeS, const int gradeE, bool sign)
	: name(name), signature(sign), gradeSign(gradeS), gradeExecute(gradeE)
{
	std::cout << "Form Parameterized constructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (signature == true)
	{
		std::cout << "Form " << name << " is already signed." << std::endl;
	}
	else if (b.getGrade() > gradeSign)
	{
		throw Form::GradeTooLowException();
	}
	else
	{
		signature = true;
	}
}

const std::string Form::getName() const
{
	return name;
}

bool Form::getSignature() const
{
	return signature;
}

int Form::getGradeSign() const
{
	return gradeSign;
}

int Form::getGradeExecute() const
{
	return gradeExecute;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form Exception: Grade too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Form Name: " << f.getName() << ", Signed: " << (f.getSignature() ? "Yes" : "No") << std::endl
		<< "Grade Required to Sign: " << f.getGradeSign() << std::endl
		<< "Grade Required to Execute: " << f.getGradeExecute() << std::endl;
	return out;
}