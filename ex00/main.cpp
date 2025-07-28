#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void moreTests()
{
    std::cout << "\n=== WrongAnimal test === \n"
              << std::endl;

    const WrongAnimal *wa = new WrongAnimal();
    const WrongAnimal *wc = new WrongCat();

    std::cout << wc->getType() << std::endl;

    wc->makeSound(); // Calls **WrongAnimal::makeSound()**!
    wa->makeSound();
    delete wa;
    delete wc;
}

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    moreTests();
    return 0;
}