#include "../../includes/Entities/entity.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace BlueJay::Entities;

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
std::shared_ptr<Entity> entity_constructor_wrapper(std::string search) {
    std::istringstream iss{search};
    boost::archive::text_iarchive ia{iss};
    return std::shared_ptr<Entity>(new Entity(ia));
}
