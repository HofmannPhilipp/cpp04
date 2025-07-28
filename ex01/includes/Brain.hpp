#pragma once
#include <string>

#define IDEAS_SIZE 100

class Brain
{
private:
    std::string ideas[IDEAS_SIZE];

public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();
    void setIdea(int index, const std::string &idea);
    void printIdeas(int n) const;
};