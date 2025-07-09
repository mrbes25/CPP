/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:47:48 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/08 22:45:57 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"
#include "Brain.hpp"

int main() {
    // Test polymorphism
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;
    
    // Test deep copy
    Dog* dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "I want to chase cats");
    
    Dog* dog2 = new Dog(*dog1); // Copy constructor
    
    // Modify dog1's idea
    dog1->getBrain()->setIdea(0, "I want to sleep");
    
    // Check that dog2's idea remains unchanged
    std::cout << "Dog1's idea: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2's idea: " << dog2->getBrain()->getIdea(0) << std::endl;
    
    delete dog1;
    delete dog2;
    
    // Test array of animals
    Animal* animals[10];
    for (int i = 0; i < 5; i++) {
        animals[i] = new Dog();
    }
    for (int i = 5; i < 10; i++) {
        animals[i] = new Cat();
    }
    
    // Delete all animals
    for (int i = 0; i < 10; i++) {
        delete animals[i];
    }
    
    return 0;
}