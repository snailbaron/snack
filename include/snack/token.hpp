#pragma once

#include "snack/stream.hpp"

#include <istream>
#include <ostream>
#include <string>

namespace snack {

struct Token {
    enum class Type {
        Equ,
        Join,
        StartList,
        EndList,
        StartDict,
        EndDict,
        SingleQuote,
        DoubleQuote,
        Backtick,
        Literal,
        End,
    };

    Type type;
    std::string text;
};
std::ostream& operator<<(std::ostream& output, const Token& token);

class Tokenizer {
public:
    Tokenizer(std::istream& input);

    Token operator()();

private:
    Stream _stream;
};

} // namespace snack
