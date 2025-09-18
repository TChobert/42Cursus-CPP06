#include <iostream>
#include "Base.hpp"

int main() {

	std::srand(std::time(0));
	for (int i = 0; i < 10; i++) {
		std::cout << "=== Test " << i + 1 << " ===" << std::endl;

		Base* obj = generate();
		if (!obj) {
			std::cout << "generate() returned NULL" << std::endl;
			continue;
		}

		std::cout << "With POINTER : ";
		identify(obj);

		std::cout << "With REFERENCE : ";
		identify(*obj);

		delete obj;
		std::cout << std::endl;
	}

	std::cout << "=== Manual testing ===" << std::endl;
	A a;
	B b;
	C c;

	std::cout << "Objet A -> ";
	identify(&a);
	identify(a);

	std::cout << "Objet B -> ";
	identify(&b);
	identify(b);

	std::cout << "Objet C -> ";
	identify(&c);
	identify(c);

	return (EXIT_SUCCESS);
}
