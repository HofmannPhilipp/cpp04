#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
    std::cout << "Cat Default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Deconstructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "🐱 Meow~" << std::endl;
}

Brain &Cat::getBrain()
{
    return *brain;
}