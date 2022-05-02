#pragma once

#include <array>
#include <string>

namespace BlueJay::Technical::Persistence {
   enum Role { WORKER, SSV, MANAGER };

   class Credentials {
     public:
      Credentials();

      Credentials(std::string, std::string);

      std::string getUserName() const;
      std::string getPassword() const;
      Role getRole() const;

      bool operator==(std::array<std::string, 2>);

     private:
      std::string _username;
      std::string _password;
      Role _role;
   };
}  // namespace BlueJay::Technical::Persistence
