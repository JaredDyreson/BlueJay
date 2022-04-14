// STD
#include <any>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#define REDISCPP_HEADER_ONLY
#include <redis-cpp/execute.h>
#include <redis-cpp/stream.h>

struct Entity {
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& x;
    }

    int x;
    Entity(int _value) { x = _value; }
    Entity(){};
};

class Connection {
   public:
    Connection(std::string /* IP Address */, std::string /* port */);

    template <typename... TArgs>
    inline auto execute(TArgs&&...);
    void set_value(std::string, std::string);
    inline auto get(std::string);

   private:
    std::shared_ptr<std::iostream> _stream;
};

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

inline auto Connection::get(std::string key) {
    return this->execute("get", key);
}

int main() {
    Connection conn = Connection("localhost", "6379");
    conn.set_value("hello", "world");
    {
        std::stringstream ss;
        boost::archive::text_oarchive oa{ss};

        const Entity value = Entity(1);
        oa << value;
        conn.set_value("my_example", ss.str());
        std::cout << conn.get("my_example").as<std::string>() << std::endl;

        std::istringstream iss{conn.get("my_example").as<std::string>()};
        boost::archive::text_iarchive ia{iss};
        Entity restored;
        ia >> restored;
        std::cout << restored.x << std::endl;
    }
}

