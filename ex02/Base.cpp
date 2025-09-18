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

	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "Type A" << std::endl;
		(void)a;
		return ;
	} catch (std::bad_cast&) {}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "Type B" << std::endl;
		(void)b;
		return ;
	} catch (std::bad_cast&) {}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "Type C" << std::endl;
		(void)c;
		return ;
	} catch (std::bad_cast&) {}
}
