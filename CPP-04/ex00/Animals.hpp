/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 09:46:22 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/09 09:47:54 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALS_HPP
# define ANIMALS_HPP

#include <string>
#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        // Orthodox Cononical Form
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal(); // virtua dextructor is important for polymorphism
		// when using the virtual destructor the compiler looks at the object and delets the most derived object first

        std::string getType() const;
        virtual void makeSound() const; // virtual function enables polymorphism behavior
};

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog&);
        Dog& operator=(const Dog&);
        ~Dog();
        void makeSound() const; // overrides
};

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat&);
        Cat& operator=(const Cat&);
        ~Cat();
        void makeSound() const; // overrides
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
        virtual ~WrongAnimal(); // removing the virtual would stop the destruction of Wrongat object

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
