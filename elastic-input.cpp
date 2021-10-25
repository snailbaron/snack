#include "snack/elastic-input.hpp"

ElasticInput::ElasticInput(const std::filesystem::path& path)
    : _fileInput(path)
    , _ref(_fileInput)
{ }

ElasticInput::ElasticInput(std::istream& input)
    : _ref(input)
{ }
