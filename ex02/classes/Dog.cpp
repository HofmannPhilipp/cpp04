
#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
    std::cout << "Dog Default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Deconstructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "🐶 Woof! Woof!" << std::endl;
}

Brain &Dog::getBrain()
{
    return *brain;
}