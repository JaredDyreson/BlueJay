template <std::size_t Dimensions>
std::array<std::string, Dimensions> utils::split(std::string expression,
                                                 std::string delimiter) {
    /*
     * Take in a string and split on a
     * delimiter, such as '&' and return a fixed length list of values
     * This is used for structured bindings
     */

    long long int start = 0U;
    auto end = expression.find(delimiter);
    std::array<std::string, Dimensions> contents;
    int i = 0;
    std::string line;

    while (end != std::string::npos) {
        line = expression.substr(start, end - start);
        start = end + delimiter.length();
        end = expression.find(delimiter, start);
        contents[i++] = line;
    }

    contents[i] = expression.substr(start, end - start);

    return contents;
}

utils::CredentialsPayload utils::parseBody(std::array<std::string, 2> input) {
    std::array<std::string, 2> contents;
    int i = 0;
    std::for_each(std::begin(input), std::end(input),
                  [&](const std::string value) {
                      const auto& [_, content] = utils::split<2>(value, "=");
                      contents[i++] = content;
                  });
    return contents;
}
