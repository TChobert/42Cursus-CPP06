#include "Serializer.hpp"

int main() {
    Data d;

    Data* original = &d;
    uintptr_t raw = Serializer::serialize(original);
    Data* recovered = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << original << std::endl;
    std::cout << "Raw value: " << raw << std::endl;
    std::cout << "Recovered pointer: " << recovered << std::endl;

    if (recovered == original)
        std::cout << "✅ Serialization/deserialization successful!" << std::endl;
    else
        std::cout << "❌ Something went wrong." << std::endl;

    return 0;
}
