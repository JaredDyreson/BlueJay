#include "../../../includes/Technical/Persistence/credentials.hpp"
#include <string>

namespace BlueJay::Technical::Persistence {
    Credentials::Credentials(){};
    Credentials::Credentials(std::string _user, std::string _pass) {
        this->_username = _user;
        this->_password = _pass;
    }
    std::string Credentials::getUserName() const { return this->_username; }
    std::string Credentials::getPassword() const { return this->_password; }
    Role Credentials::getRole() const { return this->_role; }

}  // namespace Technical::Persistence
