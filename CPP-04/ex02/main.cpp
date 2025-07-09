/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:22:46 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/09 10:28:05 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"
#include "Brain.hpp"

int main()
{

	std::cout << "\n=== subject MAIN ===\n" << std::endl;

    // Create three different animals, all accessed through Animal pointers
    // const Animal* meta = new Animal();  // Base class object now is abstract and cannot be called directly
    const Animal* dog = new Dog();        // Dog object with Animal pointer
    const Animal* cat = new Cat();        // Cat object with Animal pointer

    // Show the types
    std::cout << "dog type: " << dog->getType() << std::endl;  // Prints "Dog"
    std::cout << "cat type: " << cat->getType() << std::endl;  // Prints "Cat"

    // THIS IS POLYMORPHISM: The correct derived class method is called
    // even though we're using base class pointers
    cat->makeSound();  // Will call Cat::makeSound() - prints "Meeooww!"
    dog->makeSound();  // Will call Dog::makeSound() - prints "Woof wof!"
    // meta->makeSound();  // Will call Animal::makeSound() - prints generic sound

    // Clean up memory
    delete dog;
    delete cat;
    // delete meta;

    std::cout << "\n=== Polymorphism Test ===\n" << std::endl;
    // Create derived class objects but use them through base class pointers
    const Animal* j = new Dog();  // j points to a Dog but through an Animal*
    const Animal* i = new Cat();  // i points to a Cat but through an Animal*

    // When delete is called on an Animal*, the virtual destructor ensures
    // that the derived class destructor is called first
    delete j;  // Calls Dog::~Dog() then Animal::~Animal()
    delete i;  // Calls Cat::~Cat() then Animal::~Animal()

	std::cout << "\n\n=== Deep Copy Test ===\n" << std::endl;
    // Create a Dog and set an idea in its Brain
    Dog* dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "I want to chase cats");

    // Create a copy of dog1 using the copy constructor
    Dog* dog2 = new Dog(*dog1);  // Should perform a deep copy

    // Modify dog1's idea - if it's a deep copy, dog2's idea shouldn't change
    dog1->getBrain()->setIdea(0, "I want to sleep");

    // Print both ideas to verify they're different (confirms deep copy)
    std::cout << "Dog1's idea: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2's idea: " << dog2->getBrain()->getIdea(0) << std::endl;

    // Clean up
    delete dog1;
    delete dog2;

	std::cout << "\n\n=== Array of Animals Test ===\n" << std::endl;
    // Create an array of Animal pointers
    Animal* animals[10];

    // Fill the first half with Dogs
    for (int i = 0; i < 5; i++) {
        animals[i] = new Dog();
    }

    // Fill the second half with Cats
    for (int i = 5; i < 10; i++) {
        animals[i] = new Cat();
    }

    // Delete all animals - virtual destructors ensure proper cleanup
    for (int i = 0; i < 10; i++) {
        delete animals[i];  // Calls the appropriate derived class destructor
    }

    return 0;

    return 0;
}
