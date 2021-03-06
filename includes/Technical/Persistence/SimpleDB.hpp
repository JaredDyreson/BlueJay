#pragma once

#include <memory>  // unique_ptr
#include <string>
#include <vector>

//#include "Technical/Logging/LoggerHandler.hpp" FIXME
//
//#include "../Logging/LoggerHandler.hpp"
#include "PersistenceHandler.hpp"
#include "credentials.hpp"

namespace BlueJay::Technical::Persistence {
   class SimpleDB : public Technical::Persistence::PersistenceHandler {
     public:
      using PersistenceHandler::PersistenceHandler;  // inherit constructors
      SimpleDB();

      // Operations
      std::vector<std::string> findRoles()
          override;  // Returns list of all legal roles
      BlueJay::Technical::Persistence::Credentials findCredentialsByName(const std::string& name)
          override;  // Returns credentials for specified user, throws
                     // NoSuchUser if user not found

      // Adaptation Data read only access.  Adaptation data is a Key/Value pair
      const std::string& operator[](const std::string& key) const override;

      ~SimpleDB() noexcept override;

     private:
      //std::unique_ptr<Technical::Logging::LoggerHandler> _loggerPtr;

      // convenience reference object enabling standard insertion syntax
      // This line must be physically after the definition of _loggerPtr
      //Technical::Logging::LoggerHandler& _logger = *_loggerPtr;

      // Property data (Key/Value pairs) off-line modifiable by the end-user
      using AdaptationData =
          std::map<std::string /*Key*/, std::string /*Value*/>;
      AdaptationData _adaptablePairs;

   };  // class SimpleDB
}  // namespace Technical::Persistence

