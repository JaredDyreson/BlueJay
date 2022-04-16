#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "../includes/connection.hpp"
#include "../includes/entity.hpp"
#include "../includes/server.hpp"

int main() {

    Server server("localhost", "8080");

    server.run(10);
    //Connection conn = Connection("localhost", "6379");
    //conn.set_value("hello", "world");
    //const Entity value = Entity(100);
    // std::istringstream iss{search};
    // boost::archive::text_iarchive ia{iss};

    // const Entity other = to_entity(value.as_string());
    // std::cout << other.x << std::endl;

    //{
        //std::stringstream ss;
        //boost::archive::text_oarchive oa{ss};

        //oa << value;
        //conn.set_value("my_example", ss.str());
        //// std::cout << conn.get("my_example").as<std::string>() << std::endl;
        //std::string search = conn.get("my_example");
        //std::shared_ptr<Entity> my_thing = example(search);
        //std::cout << my_thing->x << std::endl;
        //// ia >> restored;
    //}
}

