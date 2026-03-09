#include "Serializer.hpp"

int main()
{
	Data data;
	data.n = 42;
	data.f = 3.14f;
	data.s = "Hello, World!";

	uintptr_t raw = Serializer::serialize(&data);
	
	std::cout << "Original Data address:\t\t" << &data << std::endl;
	std::cout << "Serialized Data (uintptr_t):\t" << raw << std::endl;
	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data address:\t" << deserializedData << std::endl;

	std::cout << "\nOriginal Data contents:\n";
	std::cout << "number:\t" << data.n << std::endl;
	std::cout << "float:\t" << data.f << std::endl;
	std::cout << "string:\t" << data.s << std::endl;

	std::cout << "\nDeserialized Data contents:" << std::endl;
	std::cout << "number:\t" << deserializedData->n << std::endl;
	std::cout << "float:\t" << deserializedData->f << std::endl;
	std::cout << "string:\t" << deserializedData->s << std::endl;

	return 0;
}