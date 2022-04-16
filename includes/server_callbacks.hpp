#pragma once
#include <served/served.hpp>
#include "utils.hpp"

namespace pos::server_callbacks {
   void login_handler(served::response&, const served::request&);
};

#include "server_callbacks.tcc"
