# C++ Module 04: Polymorphism - Detailed Walkthrough

This walkthrough provides a comprehensive guide to completing Module 04 of the C++ curriculum, focusing on polymorphism, inheritance, abstract classes, and interfaces.

## Table of Contents
1. [Overview](#overview)
2. [Exercise 00: Polymorphism](#exercise-00-polymorphism)
3. [Exercise 01: Brain Class and Deep Copy](#exercise-01-brain-class-and-deep-copy)
4. [Exercise 02: Abstract Classes](#exercise-02-abstract-classes)
5. [Exercise 03: Interfaces](#exercise-03-interfaces)
6. [Common Pitfalls](#common-pitfalls)
7. [Testing Your Code](#testing-your-code)

## Overview

Module 04 explores key Object-Oriented Programming concepts:
- **Polymorphism**: Using base class pointers to call derived class methods
- **Inheritance**: Building hierarchies of related classes
- **Virtual Functions**: Enabling runtime method dispatch
- **Abstract Classes**: Creating base classes that cannot be instantiated
- **Interfaces**: Defining pure abstract classes as contracts
- **Deep Copy**: Properly handling dynamically allocated members

## Exercise 00: Polymorphism

### Step 1: Creating the Base Class `Animal`

1. Create `Animal.hpp`:
```cpp
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
protected:
    std::string type;
    
public:
    // Orthodox Canonical Form
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();
    
    // Accessors
    std::string getType() const;
    
    // Virtual function for polymorphism
    virtual void makeSound() const;
};

#endif
```

2. Implement `Animal.cpp`:
```cpp
#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "Animal assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a generic sound..." << std::endl;
}
```

### Step 2: Creating Derived Classes `Dog` and `Cat`

1. Create and implement `Dog.hpp` and `Dog.cpp`:
```cpp
// Dog.hpp
#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();
    
    void makeSound() const;
};

#endif
```

```cpp
// Dog.cpp
#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    Animal::operator=(other);
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
```

2. Implement `Cat.hpp` and `Cat.cpp` similarly.

### Step 3: Creating Wrong Classes (for demonstration)

1. Create `WrongAnimal.hpp` and `WrongAnimal.cpp`:
```cpp
// WrongAnimal.hpp
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
protected:
    std::string type;
    
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal(); // Not virtual!
    
    std::string getType() const;
    void makeSound() const; // Not virtual!
};

#endif
```

2. Create `WrongCat.hpp` and `WrongCat.cpp`.

### Step 4: Testing Polymorphism

1. Create `main.cpp`:
```cpp
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    // Correct polymorphism
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // Will output Cat sound
    j->makeSound(); // Will output Dog sound
    meta->makeSound(); // Will output Animal sound
    
    // Clean up
    delete meta;
    delete j;
    delete i;
    
    // Demonstrate incorrect polymorphism
    const WrongAnimal* wrongCat = new WrongCat();
    wrongCat->makeSound(); // Will output WrongAnimal sound, not WrongCat!
    delete wrongCat;
    
    return 0;
}
```

### Step 5: Compilation and Testing

1. Create a Makefile:
```makefile
NAME    = animal

CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS    = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
    rm -f $(OBJS)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

2. Compile and run:
```
make
./animal
```

## Exercise 01: Brain Class and Deep Copy

### Step 1: Create the Brain Class

1. Create `Brain.hpp` and `Brain.cpp`:
```cpp
// Brain.hpp
#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {
private:
    std::string ideas[100];
    
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();
    
    std::string getIdea(int index) const;
    void setIdea(int index, const std::string& idea);
};

#endif
```

```cpp
// Brain.cpp
#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = "Empty idea";
    }
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return ideas[index];
    return "Invalid idea index";
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}
```

### Step 2: Update Dog and Cat Classes with Brain

1. Modify `Dog.hpp` and `Dog.cpp`:
```cpp
// Dog.hpp
#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* brain;
    
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();
    
    void makeSound() const;
    Brain* getBrain() const;
};

#endif
```

```cpp
// Dog.cpp
#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain); // Deep copy
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain); // Deep copy
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}
```

2. Modify `Cat.hpp` and `Cat.cpp` similarly.

### Step 3: Test Deep Copy

1. Update `main.cpp`:
```cpp
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

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
```

### Step 4: Compilation and Testing

1. Update your Makefile to include the new files:
```makefile
SRCS    = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
```

2. Compile and run:
```
make
./animal
```

## Exercise 02: Abstract Classes

### Step 1: Make Animal an Abstract Class

1. Modify `Animal.hpp`:
```cpp
virtual void makeSound() const = 0; // Pure virtual function
```

2. Remove the implementation of `makeSound()` from `Animal.cpp`.

### Step 2: Update Your Main Function

1. Update `main.cpp`:
```cpp
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
    // This would not compile anymore:
    // const Animal* meta = new Animal();
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound();
    j->makeSound();
    
    delete j;
    delete i;
    
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
```

### Step 3: Compilation and Testing

1. Compile and run:
```
make
./animal
```

## Exercise 03: Interfaces

### Step 1: Create AMateria Interface

1. Create `AMateria.hpp` and `AMateria.cpp`:
```cpp
// AMateria.hpp
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

class AMateria {
protected:
    std::string type;
    
public:
    AMateria(std::string const & type);
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();
    
    std::string const & getType() const;
    
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;
};

#endif
```

```cpp
// AMateria.cpp
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : type(type) {
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

AMateria::~AMateria() {
}

std::string const & AMateria::getType() const {
    return type;
}
```

### Step 2: Create Concrete Materias (Ice and Cure)

1. Create `Ice.hpp` and `Ice.cpp`:
```cpp
// Ice.hpp
#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    ~Ice();
    
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
```

```cpp
// Ice.cpp
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice& other) : AMateria(other) {
}

Ice& Ice::operator=(const Ice& other) {
    AMateria::operator=(other);
    return *this;
}

Ice::~Ice() {
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
```

2. Create `Cure.hpp` and `Cure.cpp` similarly.

### Step 3: Create Character Interface and Implementation

1. Create `ICharacter.hpp`:
```cpp
// ICharacter.hpp
#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>

class AMateria;

class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif
```

2. Create `Character.hpp` and `Character.cpp`:
```cpp
// Character.hpp
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];
    
public:
    Character(std::string const & name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();
    
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
```

```cpp
// Character.cpp
#include "Character.hpp"

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        
        // Delete current inventory
        for (int i = 0; i < 4; i++) {
            delete inventory[i];
            inventory[i] = NULL;
        }
        
        // Deep copy of other's inventory
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        delete inventory[i];
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m)
        return;
        
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->use(target);
    }
}
```

### Step 4: Create MateriaSource Interface and Implementation

1. Create `IMateriaSource.hpp`:
```cpp
// IMateriaSource.hpp
#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
```

2. Create `MateriaSource.hpp` and `MateriaSource.cpp`:
```cpp
// MateriaSource.hpp
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* templates[4];
    
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();
    
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif
```

```cpp
// MateriaSource.cpp
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        if (other.templates[i])
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        // Delete current templates
        for (int i = 0; i < 4; i++) {
            delete templates[i];
            templates[i] = NULL;
        }
        
        // Deep copy other's templates
        for (int i = 0; i < 4; i++) {
            if (other.templates[i])
                templates[i] = other.templates[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        delete templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return;
        
    for (int i = 0; i < 4; i++) {
        if (!templates[i]) {
            templates[i] = m;
            return;
        }
    }
    delete m; // If inventory is full, delete the materia
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (templates[i] && templates[i]->getType() == type) {
            return templates[i]->clone();
        }
    }
    return NULL;
}
```

### Step 5: Test the System

1. Create or update `main.cpp`:
```cpp
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    
    return 0;
}
```

### Step 6: Compilation and Testing

1. Update your Makefile:
```makefile
SRCS    = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
```

2. Compile and run:
```
make
./materia
```

## Common Pitfalls

1. **Missing Virtual Destructors**: Always make base class destructors virtual to ensure proper cleanup.

2. **Memory Leaks**: Be careful with dynamic memory, especially in copy constructors and assignment operators.

3. **Shallow Copy**: Remember to implement deep copy for classes with pointer members.

4. **Pure Virtual Functions**: A class with at least one pure virtual function cannot be instantiated.

5. **Multiple Definitions**: Don't implement the same function in multiple .cpp files.

6. **Resource Management**: Watch for leaks in unequip method that doesn't delete the materia.

## Testing Your Code

1. **Memory Leak Check**:
```
valgrind --leak-check=full ./your_program
```

2. **Copy Test**: Test copying objects to ensure deep copy works correctly:
```cpp
Dog dog1;
dog1.getBrain()->setIdea(0, "Original idea");

Dog dog2 = dog1; // Copy
dog1.getBrain()->setIdea(0, "Changed idea");

// dog2's idea should still be "Original idea"
```

3. **Polymorphism Test**: Test that virtual functions work correctly:
```cpp
Animal* a = new Dog();
a->makeSound(); // Should print Dog sound, not Animal sound
delete a;
```

4. **Abstract Class Test**: Ensure you cannot instantiate abstract classes:
```cpp
// This should not compile if Animal is abstract:
Animal a;
```

I hope this walkthrough helps you complete Module 04 successfully!
