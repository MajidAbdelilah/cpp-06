#include "Serializer.hpp"
#include <stdexcept>

uintptr_t Serializer::serialize(Data* ptr) {
    if (ptr == nullptr) {
        throw std::invalid_argument("Null pointer passed to serialize");
    }
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    if (raw == 0) {
        throw std::invalid_argument("Null raw value passed to deserialize");
    }
    return reinterpret_cast<Data*>(raw);
}