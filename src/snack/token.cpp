#include "error.hpp"
#include "token.hpp"

#include <cstdio>

namespace snack {

std::ostream& operator<<(std::ostream& output, const Token& token)
{
    switch (token.type) {
        case Token::Type::Equ: return output << "=";
        case Token::Type::Join: return output << ".";
        case Token::Type::StartList: return output << "[";
        case Token::Type::EndList: return output << "]";
        case Token::Type::StartDict: return output << "{";
        case Token::Type::EndDict: return output << "}";
        case Token::Type::SingleQuote: return output << "'";
        case Token::Type::DoubleQuote: return output << "\"";
        case Token::Type::Backtick: return output << "`";
        case Token::Type::Literal:
            return output << "literal [" << token.text << "]";
        case Token::Type::End: return output << "end";
    }
    return output;
}

Tokenizer::Tokenizer(std::istream& input)
    : _stream(input)
{ }

Token Tokenizer::operator()()
{
    _stream.skip([] (int c) { return std::isspace(c); });

    if (_stream.peek() == EOF) {
        return {.type = Token::Type::End};
    }

    if (_stream.tryRead('=')) {
        return {.type = Token::Type::Equ, .text = "="};
    }
    if (_stream.tryRead('.')) {
        return {.type = Token::Type::Join, .text = "."};
    }
    if (_stream.tryRead('[')) {
        return {.type = Token::Type::StartList, .text = "["};
    }
    if (_stream.tryRead(']')) {
        return {.type = Token::Type::EndList, .text = "]"};
    }
    if (_stream.tryRead('{')) {
        return {.type = Token::Type::StartDict, .text = "{"};
    }
    if (_stream.tryRead('}')) {
        return {.type = Token::Type::EndDict, .text = "}"};
    }

    for (char c : {'"', '\'', '`'}) {
        if (_stream.peek() == c) {
            auto text = _stream.readUntil(c, 2);
            return {.type = Token::Type::Literal, .text = std::move(text)};
        }
    }

    throw Error{
        std::string{"unexpected symbol: "} + (char)_stream.peek()};
}

} // namespace snack
