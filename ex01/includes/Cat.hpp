#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
private:
    Brain *brain;

public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat() override;
    void makeSound() const override;
    Brain &getBrain();
};