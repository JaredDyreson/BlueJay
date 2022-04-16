#pragma once

#include <array>
#include <string>

namespace utils {
   template <std::size_t Dimensions>
   std::array<std::string, Dimensions> split(std::string, std::string);
};

#include "utils.tcc"
