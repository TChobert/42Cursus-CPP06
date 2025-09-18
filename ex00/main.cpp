#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

// void runTest(const std::string& input) {
// 	std::cout << "\n========================================" << std::endl;
// 	std::cout << "🔎 Testing input: \"" << input << "\"" << std::endl;
// 	std::cout << "----------------------------------------" << std::endl;
// 	ScalarConverter::convert(input);
// 	std::cout << "========================================\n" << std::endl;
// }

//int main(void) {
// std::cout << "🚀 ScalarConverter Test Suite 🚀\n" << std::endl;

	// runTest("a");
	// runTest("Z");
	// runTest("!");
	// runTest("7");

	// runTest("0");
	// runTest("42");
	// runTest("-42");
	// runTest("127");
	// runTest("128");
	// runTest("2147483647");
	// runTest("-2147483648");
	// runTest("2147483648");
	// runTest("-2147483649");

	// runTest("42.0f");
	// runTest("3.14f");
	// runTest("-0.5f");

	// runTest("42.0");
	// runTest("3.1415926535");
	// runTest("-0.0000001");

	// runTest("340282346638528859811704183484516925440.0f");
	// runTest("1e39f");
	// runTest("1e309");

	// runTest("nan");
	// runTest("+inf");
	// runTest("-inf");
	// runTest("+inff");
	// runTest("-inff");
//}

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error! Usage: convert <value>" << std::endl;
		return (EXIT_FAILURE);
	}
	
	ScalarConverter::convert(av[1]);
	return (EXIT_SUCCESS);
}
