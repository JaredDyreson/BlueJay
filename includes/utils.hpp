#pragma once

#include <algorithm>
#include <array>
#include <string>

namespace utils {
   using CredentialsPayload = std::array<std::string, 2>;
   template <std::size_t Dimensions>
   std::array<std::string, Dimensions> split(std::string, std::string);
   CredentialsPayload parseBody(std::array<std::string, 2>);
};  // namespace utils

#include "utils.tcc"
