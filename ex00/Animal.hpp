
#include <string>

class Animal
{
protected:
    std::string name;

public:
    Animal();
    Animal(const Animal &other);
    Animal& operator=(const Animal &other);
    ~Animal();
};