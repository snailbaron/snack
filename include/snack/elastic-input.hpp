#pragma once

#include <filesystem>
#include <fstream>
#include <istream>
#include <optional>

namespace snack::internal {

class ElasticInput final {
public:
    ElasticInput(const std::filesystem::path& path);
    ElasticInput(std::istream& input);

    operator std::istream& ();

private:
    std::optional<std::ifstream> _fileInput;
    std::istream& _ref;
};

} // namespace snack::internal
