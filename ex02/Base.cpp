#include "Base.hpp"

Base::~Base() {
	//std::cout << "Base: default destructor called" << std::endl;
}

Base* generate() {

	int r = std::rand() % 3;
	if (r == 0)
		return new A();
	else if (r == 1)
		return new B();
	else return
		new C();
}

void identify(Base* p) {

	A *a = dynamic_cast<A*>(p);
	if (a) {
		std::cout << "Type A" << std::endl;
		return ;
	}
	B *b = dynamic_cast<B*>(p);
	if (b) {
		std::cout << "Type B" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C*>(p);
	if (c) {
		std::cout << "Type C" << std::endl;
	}
}

void identify(Base& p) {

	uintptr_t b = reinterpret_cast<uintptr_t>(&p);
	Base *ptr = reinterpret_cast<Base*>(b);
	return (identify(ptr));
}
