#pragma once

#include <iostream>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
namespace BlueJay::Entities {

    struct Entity {
        friend class boost::serialization::access;

        template <class Archive>
        void serialize(Archive&, const unsigned int);
        std::string as_string() const;

        template <class Archive>
        Entity(Archive&);

        Entity(){};
        Entity(int);

        int x;
    };

    std::shared_ptr<Entity> entity_constructor_wrapper(std::string);
}  // namespace BlueJay::Entities

