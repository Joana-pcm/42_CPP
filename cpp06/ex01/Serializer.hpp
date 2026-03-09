#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		~Serializer();
		Serializer &operator=(const Serializer &other);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};