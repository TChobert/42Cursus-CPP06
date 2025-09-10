#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

literalType getLiteralType(std::string& literal) {

	if (literal.size() == 1 && (!std::isdigit(static_cast<unsigned char>(literal[0]))))
		return (CHAR);
}

void convertFloat(std::string& literal) {

}

void convertInt(std::string& literal) {

}

void convertDouble(std::string& literal) {

}

void convertChar(std::string& literal) {

}

void ScalarConverter::convert(std::string& literal) {

	if (literal.empty()) {
		std::cerr << "Error: literal can't be empty." << std::endl;
	}

	literalType type = getLiteralType(literal);

	switch (type) {
		case CHAR:
			return (convertChar(literal));
		case INT:
			return (convertInt(literal));
		case FLOAT:
			return (convertFloat(literal));
		case DOUBLE:
			return (convertDouble(literal));
	}
}
