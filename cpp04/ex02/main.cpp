#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    AAnimal *dog = new Dog();
    
    std::cout << std::endl;
    std::cout << "----- Dog Test -----" << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    dog->makeSound();
    delete dog;

    std::cout << std::endl;
    std::cout << "----- Cat Test -----" << std::endl;
    AAnimal *cat = new Cat();

    std::cout << "Cat type: " << cat->getType() << std::endl;
    cat->makeSound();
    delete cat;



    std::cout << std::endl; // comment out to test abstract class
    std::cout << "----- Abstract Animal Test -----" << std::endl;
    std::cout << std::endl;
    AAnimal *meta = new AAnimal();

    std::cout << "Meta type: " << meta->getType() << std::endl;
    meta->makeSound();
    delete meta;
    std::cout << std::endl;
/*     std::cout << std::endl
    << "----- Wrong Cat Test -----" << std::endl;
    WrongAnimal *wrongCat = new WrongCat();
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound();
    delete wrongCat;

    std::cout << std::endl; // comment out to test abstract class
    std::cout << "----- Wrong Abstract Animal Test -----" << std::endl;
    WrongAnimal *wrongAnimal = new WrongAnimal();
    std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
    wrongAnimal->makeSound();
    delete wrongAnimal;
    std::cout << std::endl;
 */
    return 0;
}