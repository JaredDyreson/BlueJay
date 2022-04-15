#include "../includes/entity.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

template <class Archive>
void Entity::serialize(Archive& ar, const unsigned int version) {
    ar& x;
}

Entity::Entity(int value) {
    this->x = value;
}

template <class Archive>
Entity::Entity(Archive& archive) {
    archive >> *this;
}

std::string Entity::as_string() const {
    std::stringstream ss;
    boost::archive::text_oarchive oa{ss};
    oa << this;
    return ss.str();
}
std::shared_ptr<Entity> example(std::string search) {
    std::istringstream iss{search};
    boost::archive::text_iarchive ia{iss};
    return std::shared_ptr<Entity>(new Entity(ia));
}

// Entity to_entity(std::string search) {
// Entity restored;
//{
// std::istringstream iss{search};
// boost::archive::text_iarchive ia{iss};
// ia >> restored;
//}

// return restored;
//}
