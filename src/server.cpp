#include "../includes/server.hpp"
#include "../includes/utils.hpp"
#include "../includes/server_callbacks.hpp"

Server::Server(std::string _ip, std::string _port) {
    //auto handler = [](served::response& res, const served::request& req) {
        //if (req.header("Content-Type") != "application/json") {
            //served::response::stock_reply(400, res);
            //return;
        //};
        //const auto& [name, password] = utils::split<2>(req.body(), "&");

        //// std::vector<std::string> _split = split(req.body(), "&");
        //// for (std::string element : _split) {
        ////// std::map<std::string, std::string> a =
        ///// parse_credentials(element);
        //// for (const auto& [key, value] : parse_credentials(element)) {
        //// std::cout << key << " " << value << std::endl;
        ////}
        ////}
        //res << req.url().fragment();
    //};
    this->_handler =
        std::shared_ptr<served::multiplexer>(new served::multiplexer());
    (*this)._handler->handle("/login").post(pos::server_callbacks::login_handler);

    this->_server = std::shared_ptr<served::net::server>(
            new served::net::server(_ip, _port, *this->_handler));
}

void Server::run(int threads) {
    (*this)._server->run(threads);
}

void Server::stop() {
    (*this)._server->stop();
}
