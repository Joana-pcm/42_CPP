#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), signature(false), gradeSign(150), gradeExecute(150)
{
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

AForm::AForm(const AForm &other)
	: name(other.name), signature(other.signature), gradeSign(other.gradeSign), gradeExecute(other.gradeExecute)
{
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int gradeS, const int gradeE, bool sign)
	: name(name), signature(sign), gradeSign(gradeS), gradeExecute(gradeE)
{
	std::cout << "AForm Parameterized constructor called" << std::endl;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (signature == true)
	{
		std::cout << "AForm " << name << " is already signed." << std::endl;
	}
	else if (b.getGrade() > gradeSign)
	{
		std::cout << b.getName() << " can't sign " << this->getName() << std::endl;
		throw AForm::GradeTooLowException();
	}
	else
	{
		signature = true;
	}
}

const std::string AForm::getName() const
{
	return name;
}

bool AForm::getSignature() const
{
	return signature;
}

int AForm::getGradeSign() const
{
	return gradeSign;
}

int AForm::getGradeExecute() const
{
	return gradeExecute;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm Exception: Grade too low!";
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "AForm Name: " << f.getName() << ", Signed: " << (f.getSignature() ? "Yes" : "No") << std::endl
		<< "Grade Required to Sign: " << f.getGradeSign() << std::endl
		<< "Grade Required to Execute: " << f.getGradeExecute() << std::endl;
	return out;
}