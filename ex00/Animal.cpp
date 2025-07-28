
#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : name(other.name)
{
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->name = other.name;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Deconstructor called" << std::endl;
}