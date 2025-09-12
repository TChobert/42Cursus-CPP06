#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

void runTest(const std::string& input) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "🔎 Testing input: \"" << input << "\"" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    ScalarConverter::convert(input);
    std::cout << "========================================\n" << std::endl;
}

int main() {
    std::cout << "🚀 ScalarConverter Test Suite 🚀\n" << std::endl;

    // 🔤 Cas simples (chars)
    runTest("a");      // caractère affichable
    runTest("Z");      // autre caractère affichable
    runTest("!");      // symbole affichable
    runTest("7");      // chiffre interprété comme int, pas comme char

    // 🔢 Cas entiers
    runTest("0");
    runTest("42");
    runTest("-42");
    runTest("127");    // limite haute du char signé
    runTest("128");    // hors limite char signé
    runTest("2147483647");   // int max
    runTest("-2147483648");  // int min
    runTest("2147483648");   // dépasse int max
    runTest("-2147483649");  // dépasse int min

    // 🌊 Floats simples
    runTest("42.0f");
    runTest("3.14f");
    runTest("-0.5f");

    // 🌊 Doubles simples
    runTest("42.0");
    runTest("3.1415926535");
    runTest("-0.0000001");

    // 🌋 Valeurs extrêmes
    runTest("340282346638528859811704183484516925440.0f"); // float max approx
    runTest("1e39f");   // float overflow -> inf
    runTest("1e309");   // double overflow -> inf

    // 🤯 Cas spéciaux
    runTest("nan");
    runTest("+inf");
    runTest("-inf");

    return 0;
}
