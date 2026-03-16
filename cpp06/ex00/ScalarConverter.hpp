#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &other);
		static void convertChar(const std::string& literal);
		static void convertInt(const std::string& literal);
		static void convertFloat(const std::string& literal);
		static void convertDouble(const std::string& literal);
		static void convertPseudo(const std::string& literal);
		static bool isChar(const std::string& literal);
		static bool isInt(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);
		static bool isPseudo(const std::string& literal);
	public:
		static void convert(const std::string& literal);
};