#pragma once

#include <any>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "../../Technical/Persistence/credentials.hpp"

namespace BlueJay::Domain::Session {

   using BlueJay::Technical::Persistence::
       Credentials;  // Import the credentials type from the lower layer and
                     // publish it as your own

   class SessionHandler {
     public:
      struct SessionException : std::runtime_error {
         using runtime_error::runtime_error;
      };
      struct BadCommand : SessionException {
         using SessionException::SessionException;
      };

      static std::unique_ptr<SessionHandler> createSession(const Credentials&);

      virtual std::vector<std::string> getCommands() = 0;
      virtual std::any executeCommand(const std::string&,
                                      const std::vector<std::string>&) = 0;

      virtual ~SessionHandler() noexcept = 0;

     protected:
      SessionHandler& operator=(const SessionHandler&) =
          default;  // copy assignment
      SessionHandler& operator=(SessionHandler&&) =
          default;  // move assignment (std::move semantics)
   };
}  // namespace BlueJay::Domain::Session
