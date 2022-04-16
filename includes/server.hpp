#pragma once

#include <string>
#include <memory>
#include <served/served.hpp>

class Server {
   public:
      Server(std::string /* ip address */, std::string /* port */);
      void run(int /* threads */);
      void stop();

   private:
      std::shared_ptr<served::net::server> _server;
      std::shared_ptr<served::multiplexer> _handler;
      //served::multiplexer _handler;
};
