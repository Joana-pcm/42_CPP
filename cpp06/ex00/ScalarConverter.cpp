#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal)
{
	if (isChar(literal))
		convertChar(literal);
	else if (isInt(literal))
		convertInt(literal);
	else if (isFloat(literal))
		convertFloat(literal);
	else if (isDouble(literal))
		convertDouble(literal);
	else
		std::cout << "Invalid literal: " << literal << std::endl;
}

void ScalarConverter::convertChar(const std::string& literal)
{
	std::cout << "------ Converting char ------\n\n";
	char c = literal[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertInt(const std::string& literal)
{
	std::cout << "------ Converting int ------\n\n";
	int i = std::atoi(literal.c_str());
	std::cout << "char: ";
	if (i >= 32 && i <= 126)
		std::cout << "'" << static_cast<char>(i) << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convertFloat(const std::string& literal)
{
	std::cout << "------ Converting float ------\n\n";
	float f = std::atof(literal.c_str());
	std::cout << "char: ";
	if (f >= 32 && f <= 126)
		std::cout << "'" << static_cast<char>(f) << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertDouble(const std::string& literal)
{
	std::cout << "------ Converting double ------\n\n";
	double d = std::strtod(literal.c_str(), NULL);
	std::cout << "char: ";
	if (d >= 32 && d <= 126)
		std::cout << "'" << static_cast<char>(d) << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

bool ScalarConverter::isChar(const std::string& literal)
{
	return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal)
{
	size_t i = 0;
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	for (; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	size_t i = 0;
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	bool hasDecimal = false;
	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDecimal)
				return false;
			hasDecimal = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
	}
	return literal[literal.length() - 1] == 'f';
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	size_t i = 0;
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	bool hasDecimal = false;
	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDecimal)
				return false;
			hasDecimal = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}