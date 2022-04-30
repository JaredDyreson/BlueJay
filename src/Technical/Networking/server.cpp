#include "../../../includes/Technical/Networking/server.hpp"
#include "../../../includes/Technical/Networking/server_callbacks.hpp"
#include "../../../includes/utils.hpp"

using namespace BlueJay::Technical::Networking;

AuthenticationServer::AuthenticationServer(std::string _ip, std::string _port) {
    this->_handler =
        std::shared_ptr<served::multiplexer>(new served::multiplexer());
    (*this)._handler->handle("/login").post(
        server_callbacks::login_handler); // FIXME

    this->_server = std::shared_ptr<served::net::server>(
        new served::net::server(_ip, _port, *this->_handler));
}

void AuthenticationServer::run(int threads) {
    (*this)._server->run(threads);
}

void AuthenticationServer::stop() {
    (*this)._server->stop();
}
