#pragma once

#include <any>
#include <map>
#include <vector>

#include "../../../includes/Technical/Persistence/credentials.hpp"
#include "./SessionHandler.hpp"

namespace BlueJay::Domain::Session {
   class SessionBase : public BlueJay::Domain::Session::SessionHandler {
      SessionBase(const std::string&, const Credentials&);

      std::vector<std::string> getCommands() override;

      std::any executeCommand(const std::string&,
                              const std::vector<std::string>&) override;

     protected:
     public:
      using DispatchTable =
          std::map<std::string,
                   std::any (*)(BlueJay::Domain::Session::SessionBase&,
                                const std::vector<std::string>&)>;
      friend class Policy;

      // TODO: Logger
      Credentials const _credentials;
      std::string const _name = "Undefined";
      DispatchTable _commandDispatch;
   };

   struct ClerkSession : BlueJay::Domain::Session::SessionBase {
      ClerkSession(const Credentials&);
   };

   struct SSVSession : BlueJay::Domain::Session::SessionBase {
      SSVSession(const Credentials&);
   };
}  // namespace BlueJay::Domain::Session
