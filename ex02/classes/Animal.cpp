
#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
    std::cout << "Animal Default constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal &other) : type(other.type)
{
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Deconstructor called" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}
