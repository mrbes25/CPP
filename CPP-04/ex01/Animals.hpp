/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 09:55:57 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/09 10:17:30 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALS_HPP
# define ANIMALS_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

// Base Class
// Polymorphism because of virtual functions
class Animal
{
    protected:
        std::string type;
    public:
        // Orthodox Cononical Form
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();

        std::string getType() const;
        virtual void makeSound() const; // virtual function allows child classes to implement their own
};

class Dog : public Animal
{
    private:
        Brain* brain; // Dynamic memory
    public:
        Dog();
        Dog(const Dog&); // makes deep copy
        Dog& operator=(const Dog&); // makes deep assignment operator
        ~Dog();
        void makeSound() const; // overrides
        Brain* getBrain() const; // access to brain
};

class Cat : public Animal
{
    private:
        Brain* brain;
    public:
        Cat();
        Cat(const Cat&);
        Cat& operator=(const Cat&);
        ~Cat();
        void makeSound() const; // overrides
        Brain* getBrain() const;
};

class WrongAnimal
{
    protected:
        std::string type;
    public:
        // Orthodox Cononical Form
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual ~WrongAnimal();

        std::string getType() const;
        void makeSound() const; // non virtual makeSound function
};

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat&);
        WrongCat& operator=(const WrongCat&);
        ~WrongCat();
};
#endif
