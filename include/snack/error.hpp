#pragma once

#include <exception>
#include <sstream>
#include <string_view>

namespace snack {

class Error : std::exception {
public:
    Error(int lineNumber, int columnNumber, std::string_view message)
    {
        auto stream = std::ostringstream{};
        stream << std::string(columnNumber - 1, ' ') << "^\n" <<
            lineNumber << ":" << columnNumber << ": " << message;
        _message = stream.str();
    }

    const char* what() const noexcept override
    {
        return _message.c_str();
    }

private:
    std::string _message;
};

} // namespace snack
