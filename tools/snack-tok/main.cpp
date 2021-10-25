#include <snack.hpp>

#include <iostream>

int main()
{
    auto t = snack::Tokenizer{std::cin};
    for (auto token = t(); token.type != snack::Token::Type::End; token = t()) {
        std::cout << token << "\n";
    }
}
