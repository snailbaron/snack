#include "snack/token.hpp"

#include <cstdio>

namespace snack {

std::ostream& operator<<(std::ostream& output, const Token& token)
{
    switch (token.type) {
        case Token::Type::Integer: output << "int";
        case Token::Type::Decimal: output << "dec";
        case Token::Type::String: output << "str";
        case Token::Type::Equ: output << "=";
        case Token::Type::Open: output << "{";
        case Token::Type::Close: output << "}";
        case Token::Type::End: output << "end";
    }

    if (token.type != Token::Type::End) {
        output << " [" << token.text << "]";
    }

    return output;
}

Tokenizer::Tokenizer(std::istream& input)
    : _stream(input)
{ }

Token Tokenizer::operator()()
{
    if (!_input.good()) {
        return {.type = Token::Type::End};
    }

    int c = _input.get();

    while (std::isspace(c)) {
        c = _input.get();
    }

    if (c == '"') {
        std::string text = "\"";
        c = _input.get();
        while (c != '"' && c != EOF) {
            text += c;
            c = _input.get();
        }
        if (c == '"') {
            text += c;
        }
        c = _input.get();
    }
}

} // namespace snack
