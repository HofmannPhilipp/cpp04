#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat Default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Deconstructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "🐱 Meow~" << std::endl;
}