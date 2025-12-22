#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << std::endl << "----- Construct Shelter -----" 
    << std::endl << std::endl;
    Animal *shelter[4] = {new Dog(), new Cat(), new Dog(), new Cat()};
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (shelter[i]->getType() == "Dog")
            (shelter[i]->getBrain())->setIdea(0, "I want to play fetch!");
        else if (shelter[i]->getType() == "Cat")
            (shelter[i]->getBrain())->setIdea(0, "I want to nap!");
    }
    std::cout << std::endl
     << "----- Animal Info -----" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << std::endl;
        std::cout << "Animal Type: " << shelter[i]->getType() << std::endl;
        shelter[i]->makeSound();
        std::cout << shelter[i]->getType() << " ideas: " << (shelter[i]->getBrain())->getIdea(0) << std::endl;
    }
    std::cout << std::endl
    << "----- Cleaning Up Shelter -----" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << std::endl;
        std::cout << "Deleting Animal of type: " << shelter[i]->getType() << std::endl;
        delete shelter[i];
    }
    std::cout << std::endl

    << "----- Deep Copy Test -----" << std::endl;
    Dog *dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "I want to play fetch!");
    Dog *dog2 = new Dog(*dog1);
    std::cout << std::endl
    << "Dog1 ideas before modification: " << dog1->getBrain()->getIdea(0) << std::endl
    << "Dog2 ideas before modification: " << dog2->getBrain()->getIdea(0) << std::endl
    << std::endl;
    dog2->getBrain()->setIdea(0, "I want to chase cats!");
    std::cout << "Dog1 ideas after Dog2 modification: " << dog1->getBrain()->getIdea(0) << std::endl
    << "Dog2 ideas after modification: " << dog2->getBrain()->getIdea(0) << std::endl;
    delete dog1;
    delete dog2;

    std::cout << std::endl << "----- Wrong Shelter -----" << std::endl;
    WrongAnimal *wrongShelter[2] = {new WrongCat(), new WrongCat()};
    std::cout << std::endl;
    for (int i = 0; i < 2; i++)
    {
        if (wrongShelter[i]->getBrain() == NULL)
        {
            std::cout << "Error: WrongAnimal of type " << wrongShelter[i]->getType() << " has no brain!" << std::endl;
            delete wrongShelter[0];
            delete wrongShelter[1];
            return 1;
        }
        else
        {
            wrongShelter[i]->getBrain()->setIdea(0, "I want to nap!");
            delete wrongShelter[0];
            delete wrongShelter[1];
        }
    }
    return 0;
}