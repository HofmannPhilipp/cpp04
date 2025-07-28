#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain Default constructor called" << std::endl;
    for (int i = 0; i < IDEAS_SIZE; i++)
        this->ideas[i] = "X";
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    for (int i = 0; i < IDEAS_SIZE; i++)
        this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < IDEAS_SIZE; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Deconstructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index < IDEAS_SIZE)
        this->ideas[index] = idea;
}

void Brain::printIdeas(int n) const
{
    for (int i = 0; i < n; i++)
        std::cout << "[" << i << "] " << this->ideas[i] << std::endl;
}