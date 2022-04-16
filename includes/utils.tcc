template <std::size_t Dimensions>
std::array<std::string, Dimensions> utils::split(std::string expression,
                                                 std::string delimiter) {
    /*
     * Take in a string
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

