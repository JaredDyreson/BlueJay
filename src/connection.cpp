#define REDISCPP_HEADER_ONLY
#include <redis-cpp/execute.h>
#include <redis-cpp/stream.h>

#include "../includes/connection.hpp"

Connection::Connection(std::string _addr, std::string _port) {
    this->_stream = rediscpp::make_stream(_addr, _port);
}

template <typename... TArgs>
inline auto Connection::execute(TArgs&&... args) {
    return rediscpp::execute(*this->_stream, std::forward<TArgs>(args)...);
}

void Connection::set_value(std::string key, std::string value) {
    this->execute("set", key, value);
}

std::string Connection::get(std::string key) {
    return this->execute("get", key).as<std::string>();
}
