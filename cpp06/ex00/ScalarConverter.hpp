#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>

class ScalarConverter
{
public:
	static void convert(const std::string& literal);
private:
	static void convertChar(const std::string& literal);
	static void convertInt(const std::string& literal);
	static void convertFloat(const std::string& literal);
	static void convertDouble(const std::string& literal);
	static bool isChar(const std::string& literal);
	static bool isInt(const std::string& literal);
	static bool isFloat(const std::string& literal);
	static bool isDouble(const std::string& literal);
};