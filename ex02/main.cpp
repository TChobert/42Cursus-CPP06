#include <iostream>
#include "Base.hpp"

// Prototypes des fonctions
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    // On fait plusieurs générations pour tester les cas
    for (int i = 0; i < 10; i++) {
        std::cout << "=== Test " << i + 1 << " ===" << std::endl;

        Base* obj = generate();
        if (!obj) {
            std::cout << "generate() a retourné NULL" << std::endl;
            continue;
        }

        std::cout << "Avec pointeur : ";
        identify(obj);

        std::cout << "Avec référence : ";
        identify(*obj);

        delete obj; // libérer la mémoire
        std::cout << std::endl;
    }

    // Test manuel avec instanciations directes
    std::cout << "=== Tests manuels ===" << std::endl;
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

    return 0;
}
