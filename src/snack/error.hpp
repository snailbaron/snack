#pragma once

#include <exception>
#include <format>
#include <source_location>
#include <string>
#include <string_view>

namespace snack {

class Error : std::exception {
public:
    Error(std::string_view message, std::source_location sl = std::source_location::current())
        : _message(std::format(
            "{}:{}:{} ({}): {}",
            sl.file_name(),
            sl.line(),
            sl.column(),
            sl.function_name(),
            message))
    { }

    const char* what() const noexcept override
    {
        return _message.c_str();
    }

private:
    std::string _message;
};

} // namespace snack
