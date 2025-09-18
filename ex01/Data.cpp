#include "Data.hpp"

Data::Data(void) {}

Data::~Data(void) {}

Data::Data(const Data& other) {
	_letter = other._letter;
	_number = other._number;
}

Data& Data::operator=(const Data& other) {
	if (this != &other) {
		this->_letter = other._letter;
		this->_number = other._number;
	}
	return (*this);
}

int Data::getNumber(void) {
	return (_number);
}

char Data::getLetter(void) {
	return (_letter);
}

void Data::setNumber(int number) {
	_number = number;
}

void Data::setLetter(char letter) {
	_letter = letter;
}
