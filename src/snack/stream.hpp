#pragma once

#include <concepts>
#include <functional>
#include <istream>
#include <utility>

namespace snack {

class Stream {
public:
    Stream(std::istream& input);

    int lineNumber() const;
    int columnNumber() const;

    int peek() const;
    void skip(const std::function<bool(int)>& predicate);
    std::string readUntil(char c, int count = 1);
    bool tryRead(char c);

private:
    void advance();

    std::istream& _input;
    int _state = 0;
    int _lineNumber = 1;
    int _charNumber = 1;
};

} // namespace snack
