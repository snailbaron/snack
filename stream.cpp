#include "snack/stream.hpp"

namespace snack {

Stream::Stream(std::istream& input)
    : _input(input)
{
    _input.exceptions(std::ios::badbit | std::ios::failbit);
    _state = _input.get();
}

} // namespace snack
