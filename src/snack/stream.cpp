#include "stream.hpp"

#include <cassert>
#include <sstream>

namespace snack {

// TODO: Replace _input with Peeper, so that advance() is the only possible way
// of reading the input.

Stream::Stream(std::istream& input)
    : _input(input)
{
    _input.exceptions(std::ios::badbit | std::ios::failbit);
    _state = _input.get();
}

int Stream::lineNumber() const
{
    return _lineNumber;
}

int Stream::columnNumber() const
{
    return _charNumber;
}

int Stream::peek() const
{
    return _state;
}

void Stream::skip(const std::function<bool(int)>& predicate)
{
    while (_state != EOF && !predicate(_state)) {
        advance();
    }
}

std::string Stream::readUntil(char c, int count)
{
    std::ostringstream stream;
    int readCount = 0;
    for (; _state != EOF; advance()) {
        if (_state == c) {
            readCount++;
        }
        stream << (char)_state;
        if (readCount == count) {
            break;
        }
    }
    return stream.str();
}

bool Stream::tryRead(char c)
{
    if (_state == c) {
        advance();
        return true;
    } else {
        return false;
    }
}

void Stream::advance()
{
    assert(_state != EOF);
    bool endOfLine = (_state == '\n');
    _state = _input.get();
    if (endOfLine) {
        if (_state != EOF) {
            _lineNumber++;
            _charNumber++;
        }
    } else {
        if (_state != '\n' && _state != EOF) {
            _charNumber++;
        }
    }
}

} // namespace snack
