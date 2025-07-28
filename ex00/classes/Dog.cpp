
#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
    std::cout << "Dog Default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Deconstructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "🐶 Woof! Woof!" << std::endl;
}