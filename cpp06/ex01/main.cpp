#include "Serializer.hpp"

int main()
{
	Data data;
	data.n = 42;
	data.f = 3.14f;
	data.s = "Hello, World!";

	std::cout << "Original Data address: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data address: " << deserializedData << std::endl;

	std::cout << "Deserialized Data contents:" << std::endl;
	std::cout << "n: " << deserializedData->n << std::endl;
	std::cout << "f: " << deserializedData->f << std::endl;
	std::cout << "s: " << deserializedData->s << std::endl;

	return 0;
}