#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& str) {
    try {
        long long ll = std::stoll(str);
        if (ll < std::numeric_limits<int>::min() || ll > std::numeric_limits<int>::max()) {
            throw std::out_of_range("Overflow/Underflow");
        }
        int i = static_cast<int>(ll);
        std::cout << "int: " << i << '\n';
    } catch (std::exception& e) {
        std::cout << "int: impossible\n";
    }

    try {
        int i = std::stoi(str);
        if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) {
            throw std::out_of_range("Overflow/Underflow");
        }
        char c = static_cast<char>(i);
        if (std::isprint(c)) {
            std::cout << "char: '" << c << "'\n";
        } else {
            std::cout << "char: Non displayable\n";
        }
    } catch (std::exception& e) {
        std::cout << "char: impossible\n";
    }

    try {
        float f = std::stof(str);
        if (std::isinf(f)) {
            std::cout << "float: " << (f < 0 ? "-inf" : "+inf") << "f\n";
        } else if (std::isnan(f)) {
            std::cout << "float: nanf\n";
        } else if (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max()) {
            throw std::out_of_range("Overflow/Underflow");
        } else {
            std::cout << "float: " << f << "f\n";
        }
    } catch (std::exception& e) {
        std::cout << "float: impossible\n";
    }

    try {
        double d = std::stod(str);
        if (std::isinf(d)) {
            std::cout << "double: " << (d < 0 ? "-inf" : "+inf") << '\n';
        } else if (std::isnan(d)) {
            std::cout << "double: nan\n";
        } else if (d < -std::numeric_limits<double>::max() || d > std::numeric_limits<double>::max()) {
            throw std::out_of_range("Overflow/Underflow");
        } else {
            std::cout << "double: " << d << '\n';
        }
    } catch (std::exception& e) {
        std::cout << "double: impossible\n";
    }
}