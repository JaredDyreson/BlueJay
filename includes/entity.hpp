#pragma once

#include <iostream>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

struct Entity {
    friend class boost::serialization::access;

    template <class Archive>
    void serialize(Archive&, const unsigned int);
    std::string as_string() const;

    template <class Archive>
    Entity(Archive&);

    Entity(){};
    ~Entity(){ std::cout << "calling destructor" << std::endl; }
    Entity(int);

    int x;
};

std::shared_ptr<Entity> example(std::string);
