#include "Base.hpp"
#include <ctime>
#include <random>
#include <iostream>


int main() {
    std::srand(std::time(0));

    for (int i = 0; i < 10; ++i) {
        Base* base = generate();
        if (base == nullptr) {
            std::cerr << "Failed to generate Base instance\n";
            continue;
        }
        try {
            identify(base);
            identify(*base);
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
            delete base;
            continue;
        }
        delete base;
    }
	
	std::cout << "---------------------" << std::endl;

	Base *a = new A();
	Base *b = new B();
	Base *c = new C();

	try{
		identify(a);
		identify(b);
		identify(c);
		identify(*a);
		identify(*b);
		identify(*c);
	 } catch (const std::invalid_argument& e) {
		std::cerr << e.what() << '\n';
    }
	delete a;
	delete b;
	delete c;
    return 0;
}