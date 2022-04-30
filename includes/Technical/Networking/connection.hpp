#pragma once

#include <memory>
#include <string>

namespace BlueJay::Technical::Networking {

   class RedisConnection {
     public:
      RedisConnection(std::string /* IP Address */, std::string /* port */);

      template <typename... TArgs>
      inline auto execute(TArgs&&...);
      void set_value(std::string, std::string);
      std::string get(std::string);
      void dump();

     private:
      std::shared_ptr<std::iostream> _stream;
   };
}  // namespace BlueJay::Technical::Networking

