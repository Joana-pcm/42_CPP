#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal(); // This line will cause a compilation error because Animal is abstract
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Dog type: " << dog->getType() << std::endl;
    dog->makeSound();

    std::cout << "Cat type: " << cat->getType() << std::endl;
    cat->makeSound();

    delete meta; // This line will not be reached due to the compilation error above
    delete dog;
    delete cat;

    return 0;
}