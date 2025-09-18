#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

bool IsPrintable(const char& c) {
	return (c >= 32 && c <= 126);
}

bool isOutOfCharLimits(const long& value) {
	return (value < std::numeric_limits<unsigned char>::min() || value > std::numeric_limits<unsigned char>::max());
}

bool isOutOfIntLimits(const long& value) {
	return (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max());
}

bool isDoubleOverflow(const std::string& value) {

	double convValue = strtod(value.c_str(), NULL);
	if (std::isnan(convValue) || std::isinf(convValue)) {
		return (true);
	}
	if (convValue > std::numeric_limits<double>::max() || convValue < -std::numeric_limits<double>::max()) {
		return (true);
	}
	return (false);
}

bool isFloatOverflow(const std::string& value) {

	float f = strtof(value.c_str(), NULL);
	if (std::isnan(f) || std::isinf(f)) {
		return (true);
	}
	if (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max()) {
		return (true);
	}
	return (false);
}

bool checkStringBounds(const std::string& str, size_t size) {

	if (str.empty())
		return (false);
	if (!std::isdigit(static_cast<unsigned char>(str[0]))) {
		if (str[0] != '+' && str[0] != '-')
			return (false);
	}
	return (std::isdigit(static_cast<unsigned char>(str[size - 1])));
}

bool isValidNumericString(const std::string& literal, size_t size) {

	bool isDot = false;
	size_t start = (literal[0] == '+' || literal[0] == '-') ? 1 : 0;

	for (size_t i = start; i < size; ++i) {
		if (literal[i] == '.') {
			if (!isDot) {
				isDot = true;
				continue ;
			} else if (isDot) {
				return (false);
			}
		}
		else if (!std::isdigit(static_cast<unsigned char>(literal[i]))) {
			return (false);
		}
	}
	return (true);
}

literalType defineFLoatOrDouble(const std::string& literal, size_t pos) {

	size_t lastPoint = literal.find_last_of('.');
	if (lastPoint != pos) {
		return (UNKNOWN);
	}

	size_t size = literal.size();
	if (literal[size - 1] == 'f') {
		std::string litNoSufix = literal.substr(0, size -1);
		if (!checkStringBounds(litNoSufix, litNoSufix.size())) {
			return (UNKNOWN);
		} else {
			return (isValidNumericString(litNoSufix, litNoSufix.size()) ? FLOAT : UNKNOWN);
		}
	} else {
		if (!checkStringBounds(literal, size)) {
			return (UNKNOWN);
		} else {
			return (isValidNumericString(literal, size )? DOUBLE : UNKNOWN);
		}
	}
	return (UNKNOWN);
}

literalType getLiteralType(const std::string& literal) {

	if (literal.size() == 1 && (!std::isdigit(static_cast<unsigned char>(literal[0]))))
		return (CHAR);

	size_t pos = literal.find_first_of('.');
	if (pos != std::string::npos) {
		return (defineFLoatOrDouble(literal, pos));
	} else {
		if (!checkStringBounds(literal, literal.size()))
			return (UNKNOWN);
		for (size_t i = 1; i < literal.size(); ++i) {
			if (!std::isdigit(static_cast<unsigned char>(literal[i]))) {
				return (UNKNOWN);
			}
		}
		return (INT);
	}
	return (UNKNOWN);
}

void convertInt(const std::string& literal) {

	long double longValue = std::strtold(literal.c_str(), NULL);
	if (isOutOfIntLimits(longValue)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	} else {
		int value = static_cast<int>(longValue);
		if (isOutOfCharLimits(static_cast<long>(value))) {
			std::cout << "char: impossible" << std::endl;
		} else {
			char c = static_cast<char>(value);
			if (IsPrintable(c))
				std::cout << "char: " << c << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		std::cout << "int: " << value << std::endl;
	}

	if (isFloatOverflow(literal)) {
		std::cout << "float: impossible" << std::endl;
	} else {
		float f = static_cast<float>(longValue);
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}

	if (isDoubleOverflow(literal)) {
		std::cout << "double: impossible" << std::endl;
	} else {
		double d = static_cast<double>(longValue);
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
}

void convertFloat(const std::string& literal) {

	if (isFloatOverflow(literal)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
	} else {
		float value = strtof(literal.c_str(), NULL);
		if (value != static_cast<int>(value)) {
			std::cout << "char: impossible" << std::endl;
		} else {
			char c = static_cast<char>(value);
			if (isOutOfCharLimits(static_cast<long>(c))) {
				std::cout << "char: impossible" << std::endl;
			} else {
				if (IsPrintable(c))
					std::cout << "char: " << c << std::endl;
				else
					std::cout << "char: Non displayable" << std::endl;
			}
		}
		int i = static_cast<int>(value);
		if (isOutOfIntLimits(value) || i != value) {
			std::cout << "int: impossible" << std::endl;
		} else {
			std::cout << "int: " << i <<std::endl;
		}
		std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	}

	if (isDoubleOverflow(literal)) {
		std::cout << "double: impossible" << std::endl;
	} else {
		double d = strtod(literal.c_str(), NULL);
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
}

void convertDouble(const std::string& literal) {

	if (isDoubleOverflow(literal)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	} else {
		double value = strtod(literal.c_str(), NULL);
		if (value != static_cast<int>(value)) {
			std::cout << "char: impossible" << std::endl;
		} else {
			char c = static_cast<char>(value);
			if (isOutOfCharLimits(static_cast<long>(c))) {
				std::cout << "char: impossible" << std::endl;
			} else {
				if (IsPrintable(c))
					std::cout << "char: " << c << std::endl;
				else
					std::cout << "char: Non displayable" << std::endl;
			}
		}

		int i = static_cast<int>(value);
		if (isOutOfIntLimits(value) || i != value) {
			std::cout << "int: impossible" << std::endl;
		} else {
			std::cout << "int: " << i << std::endl;
		}

		if (isFloatOverflow(literal)) {
			std::cout << "float: impossible" << std::endl;
		} else {
			float f = static_cast<float>(value);
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		}

		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
	}
}

void convertChar(const std::string& literal) {

	char c = literal[0];

	if (!IsPrintable(c)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	int cInt = static_cast<int>(c);
	std::cout << "int: " << cInt << std::endl;

	float cFloat = static_cast<float>(c);
	std::cout << "float: " << std::fixed << std::setprecision(1) << cFloat << "f" << std::endl;

	double cDouble = static_cast<double>(c);
	std::cout << "double: " << std::fixed << std::setprecision(1) << cDouble << std::endl;
}

void handleNan(void) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void handlePositiveInf(void) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

void handleNegativeInf(void) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {

	if (literal.empty()) {
		std::cerr << "Error: literal can't be empty." << std::endl;
		return ;
	}

	if (literal == "nanf" || literal == "nan") {
		handleNan();
		return ;
	}
	if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
		handlePositiveInf();
		return ;
	}
	if (literal == "-inf" || literal == "-inff") {
		handleNegativeInf();
		return ;
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
		case UNKNOWN:
			std::cerr << "Error: unknown litteral type." << std::endl;
			return ;
	}
}
