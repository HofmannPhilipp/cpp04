#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
    std::cout << "Cat Default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Deconstructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "🐱 Meow~" << std::endl;
}