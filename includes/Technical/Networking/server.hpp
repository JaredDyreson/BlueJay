#pragma once

#include <memory>
#include <served/served.hpp>
#include <string>

namespace BlueJay::Technical::Networking {

   class AuthenticationServer {
     public:
      AuthenticationServer(std::string /* ip address */, std::string /* port */);
      void run(int /* threads */);
      void stop();

     private:
      std::shared_ptr<served::net::server> _server;
      std::shared_ptr<served::multiplexer> _handler;
   };
}  // namespace BlueJay::Technical::Networking

