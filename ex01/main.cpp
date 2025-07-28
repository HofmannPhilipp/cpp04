#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// Deep copy test for Dog (and Brain)
void deepCopyTest()
{
    std::cout << "\n=== DEEP COPY TEST ===\n"
              << std::endl;

    Dog dog1;
    dog1.getBrain().setIdea(0, "Chase the mailman");
    dog1.getBrain().setIdea(1, "Bark at strangers");

    std::cout << "\n--- Copying dog1 into dog2 ---\n"
              << std::endl;
    Dog dog2 = dog1; // Copy constructor is called here

    std::cout << "\nDog1 ideas:" << std::endl;
    dog1.getBrain().printIdeas(2);

    std::cout << "\nDog2 ideas:" << std::endl;
    dog2.getBrain().printIdeas(2);

    std::cout << "\n--- Modifying dog2's brain ---\n"
              << std::endl;
    dog2.getBrain().setIdea(0, "Sleep all day");
    dog2.getBrain().setIdea(1, "Eat food");

    std::cout << "\nDog1 ideas:" << std::endl;
    dog1.getBrain().printIdeas(2);

    std::cout << "\nDog2 ideas:" << std::endl;
    dog2.getBrain().printIdeas(2);

    std::cout << "\n>>> If the ideas are different -> Deep Copy works!\n"
              << std::endl;
}

int main()
{
    std::cout << "\n=== POLYMORPHISM TEST (delete on Animal*) ===\n"
              << std::endl;

    const Animal *dog = new Dog();
    const Animal *cat = new Cat();
    delete dog; // Dog destructor -> Brain destructor -> Animal destructor
    delete cat; // Cat destructor -> Brain destructor -> Animal destructor

    std::cout << "\n=== ARRAY TEST ===\n"
              << std::endl;

    const int size = 6;
    Animal *animals[size];

    // Fill array: first half Dogs, second half Cats
    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Deleting all animals using Animal* ---\n"
              << std::endl;
    for (int i = 0; i < size; i++)
    {
        delete animals[i];
    }

    // Deep copy test
    deepCopyTest();

    std::cout << "\n=== ALL TESTS COMPLETED ===\n"
              << std::endl;

    return 0;
}