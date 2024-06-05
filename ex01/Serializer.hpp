#pragma once
#include <cstdint>

class Data {
public:
    int a;
    double b;
};

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
private:
    Serializer() {}
};
