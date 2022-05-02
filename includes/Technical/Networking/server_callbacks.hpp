#pragma once
#include <iostream>
#include <served/served.hpp>
#include "../Persistence/credentials.hpp"
#include "../../utils.hpp"

namespace BlueJay::Technical::server_callbacks {
   void login_handler(served::response&, const served::request&);
};  // namespace BlueJay::Technical::server_callbacks

#include "server_callbacks.tcc"
