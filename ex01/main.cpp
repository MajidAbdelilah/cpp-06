#include "Serializer.hpp"
#include <cassert>
#include <stdexcept>
#include <iostream>

int main() {
    Data data;
    data.a = 10;
    data.b = 20.5;

    try {
        uintptr_t serialized = Serializer::serialize(&data);
        Data* deserialized = Serializer::deserialize(serialized);

        assert(deserialized == &data);
        assert(deserialized->a == data.a);
        assert(deserialized->b == data.b);
		std::cout << deserialized->a << std::endl;
		std::cout << deserialized->b << std::endl;
		std::cout << &data << std::endl;
		std::cout << std::hex << serialized << std::endl;
		std::cout << deserialized << std::endl;
	} catch (const std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}