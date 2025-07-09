/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 09:49:11 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/09 09:52:00 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

int main()
{
    std::cout << "\n=== subject MAIN ===" << std::endl;

    // Create three different animals, all accessed through Animal pointers
    const Animal* meta = new Animal();  // Base class object
    const Animal* dog = new Dog();        // Dog object with Animal pointer
    const Animal* cat = new Cat();        // Cat object with Animal pointer

    // Show the types
    std::cout << "dog type: " << dog->getType() << std::endl;  // Prints "Dog"
    std::cout << "cat type: " << cat->getType() << std::endl;  // Prints "Cat"

    // THIS IS POLYMORPHISM: The correct derived class method is called
    // even though we're using base class pointers
    cat->makeSound();  // Will call Cat::makeSound() - prints "Meeooww!"
    dog->makeSound();  // Will call Dog::makeSound() - prints "Woof wof!"
    meta->makeSound();  // Will call Animal::makeSound() - prints generic sound

    // Clean up memory
    delete dog;
    delete cat;
    delete meta;

    // THIS SHOWS WHAT HAPPENS WITHOUT POLYMORPHISM
    const WrongAnimal* wcat = new WrongCat();  // WrongCat object with WrongAnimal pointer
    wcat->makeSound();  // Will call WrongAnimal::makeSound() NOT WrongCat::makeSound()
                        // This prints "Ga Ga Gaaaaa" instead of a cat sound
    delete wcat;
}
