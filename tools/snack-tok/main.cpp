#include <snack.hpp>

#include <cstdlib>
#include <iostream>

int main()
{
    try {
        auto t = snack::Tokenizer{std::cin};
        for (auto token = t(); token.type != snack::Token::Type::End; token = t()) {
            std::cout << token << "\n";
        }
    } catch (const snack::Error& e) {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }
}
