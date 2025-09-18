#include "Serializer.hpp"

#include <cstdlib>

int main(void) {

	Data d;

	Data* original = &d;
	uintptr_t raw = Serializer::serialize(original);
	Data* recovered = Serializer::deserialize(raw);

	std::cout << "Original pointer: " << original << std::endl;
	std::cout << "Raw value: " << raw << std::endl;
	std::cout << "Recovered pointer: " << recovered << std::endl;

	if (recovered == original) {
		std::cout << "Serialization/deserialization successful!" << std::endl;
		return (EXIT_SUCCESS);
	}
	else {
		std::cout << "Something went wrong." << std::endl;
		return (EXIT_FAILURE);
	}
}
