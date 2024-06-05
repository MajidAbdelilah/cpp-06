#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void) {
    switch (rand() % 3) {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
    }
    return nullptr;
}

void identify(Base* p) {
    if (p == nullptr) {
        throw std::invalid_argument("Null pointer passed to identify");
    }
    if (dynamic_cast<A*>(p)) std::cout << "A\n";
    else if (dynamic_cast<B*>(p)) std::cout << "B\n";
    else if (dynamic_cast<C*>(p)) std::cout << "C\n";
	else {
		throw std::invalid_argument("Failed to identify Base instance");
	}
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p); std::cout << "A\n";
    } catch (std::bad_cast&) {
        try {
            (void)dynamic_cast<B&>(p); std::cout << "B\n";
        } catch (std::bad_cast&) {
			try{
				(void)dynamic_cast<C&>(p); std::cout << "C\n";
			}catch (std::bad_cast&) {
				throw std::invalid_argument("Failed to identify Base instance");
			}
    	}
	}
}