/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:47:45 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/08 22:42:29 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALS_HPP
# define ANIMALS_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

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
        virtual void makeSound() const;
};

class Dog : public Animal
{
    private:
        Brain* brain;
    public:
        Dog();
        Dog(const Dog&);
        Dog& operator=(const Dog&);
        ~Dog();
        void makeSound() const; // overrides
        Brain* getBrain() const;
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