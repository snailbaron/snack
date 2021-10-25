#pragma once

#include <istream>

namespace snack {

class Stream {
public:
    Stream(std::istream& input);

    // TODO: skip(callable),
    // where 'callable' is callable of int, and returns something
    // interpretable as bool (concept?)

private:
    std::istream& _input;
    int _state = 0;
};

} // namespace snack
