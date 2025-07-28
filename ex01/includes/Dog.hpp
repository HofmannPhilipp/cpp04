#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
private:
    Brain *brain;

public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog() override;
    void makeSound() const override;
    Brain &getBrain();
};