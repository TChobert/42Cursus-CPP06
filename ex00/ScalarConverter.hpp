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
	DOUBLE
};

class ScalarConverter {

	private:

	ScalarConverter(void);
	~ScalarConverter(void);

	public:

	static void convert(std::string& literal);
};
