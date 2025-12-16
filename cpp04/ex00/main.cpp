#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "----- Correct Animal Tests -----" << std::endl;
    const Animal* meta = new Animal();
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();

    std::cout << std::endl;
    std::cout << "----- Making Sounds -----" << std::endl;
    std::cout << "Meta type: " << meta->getType() << std::endl;
    meta->makeSound();
    std::cout << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    dog->makeSound();
    std::cout << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    cat->makeSound();
    std::cout << std::endl;
    std::cout << "----- Wrong Animal Tests -----" << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << std::endl;
    std::cout << "----- Making Sounds -----" << std::endl;
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound();
    std::cout << std::endl;
    std::cout << "----- Cleaning Up -----" << std::endl;
    delete meta;
    delete dog;
    delete cat;
    delete wrongCat;

    return 0;
}