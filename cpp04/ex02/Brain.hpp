#pragma once

#include <iostream>
#include <string>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    ~Brain();
    Brain(const Brain &src);
    Brain &operator=(const Brain &src);
    std::string getIdea(int index) const;
    void setIdea(int index, const std::string &idea);
};

std::ostream &operator<<(std::ostream &out, const Brain &src);