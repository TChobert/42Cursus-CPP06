#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <climits>

enum literalType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

class ScalarConverter {

	private:

	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter(void);

	public:

	static void convert(const std::string& literal);
};
