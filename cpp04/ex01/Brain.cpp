#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructed." << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructed." << std::endl;
}

Brain::Brain(const Brain &src)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
    std::cout << "Brain copy constructor called." << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
    if (this != &src)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = src.ideas[i];
    }
    return (*this);
}

std::string Brain::getIdea(int index) const
{
    if (index < 0 || index >= 100)
        return ("");
    return (this->ideas[index]);
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index < 0 || index >= 100)
        return ;
    this->ideas[index] = idea;
}

std::ostream &operator<<(std::ostream &out, const Brain &src)
{
    out << "Brain Ideas: ";
    for (int i = 0; i < 100; i++)
    {
        if (src.getIdea(i) != "")
            out << "[" << i << ": " << src.getIdea(i) << "] ";
    }
    return (out);
}