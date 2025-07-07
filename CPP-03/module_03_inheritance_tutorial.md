````markdown
# C++ Module 03: Inheritance – Step-by-Step Tutorial

This guide walks you through the Module 03 project (Inheritance) of the 42 C++ curriculum, covering Exercises 00 through 03. You will learn how to design classes, apply inheritance (single and multiple), and implement special member functions according to the Orthodox Canonical Form.

---

## Table of Contents

1. [General Rules & Setup](#general-rules--setup)
2. [Exercise 00: ClapTrap](#exercise-00-claptrap)
   - Project structure & Makefile
   - `ClapTrap` class declaration
   - Implementing member functions
   - Testing & compilation
3. [Exercise 01: ScavTrap](#exercise-01-scavtrap)
   - Inheriting from `ClapTrap`
   - Overriding constructors & `attack()`
   - Adding `guardGate()` ability
   - Tests
4. [Exercise 02: FragTrap](#exercise-02-fragtrap)
   - Inheritance & special messages
   - Adding `highFivesGuys()` ability
   - Tests
5. [Exercise 03: DiamondTrap](#exercise-03-diamondtrap)
   - Multiple inheritance (FragTrap + ScavTrap)
   - Managing name ambiguity
   - Implementing `whoAmI()`
   - Tests
6. [Submission & Peer-Evaluation](#submission--peer-evaluation)

---

## General Rules & Setup

- **Compiler flags:** Always compile with:
  ```bash
  c++ -Wall -Wextra -Werror -std=c++98 <files...> -o <executable>
````

- `-std=c++98` ensures C++98 compliance.

- No use of `printf`, `malloc`/`free`, or external libraries beyond the standard library.

- Forbidden: `using namespace`, `friend`, STL containers/algorithms until Modules 08–09.

- **Orthodox Canonical Form (OCF):** For each class, implement:

  1. Default constructor
  2. Copy constructor
  3. Copy assignment operator
  4. Destructor

- **Memory management:** If you use `new`, pair with `delete` to avoid leaks.

- **File structure & naming:**

  - Directories: `ex00/`, `ex01/`, `ex02/`, `ex03/`.
  - Headers in `ClassName.hpp`, source files in `ClassName.cpp`.
  - Include guards in each header.

- **Makefile:** Create a Makefile in each exercise directory to build the executable and a `clean`/`fclean` target.

---

## Exercise 00: ClapTrap

### 1. Project Structure

```text
ex00/
├─ ClapTrap.hpp
├─ ClapTrap.cpp
├─ main.cpp
├─ Makefile
```

### 2. `ClapTrap.hpp`

```cpp
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:
    // Orthodox Canonical Form
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();

    // Core behaviors
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
```

**Concepts:**

- **Encapsulation:** private members, public methods.
- **OCF:** four special member functions.
- **Include guards:** prevent double inclusion.

### 3. `ClapTrap.cpp`

```cpp
#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
    : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap <" << _name << "> constructed!\n";
}

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap <" << _name << "> constructed!\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    *this = other;
    std::cout << "ClapTrap <" << _name << "> copied!\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap <" << _name << "> destructed!\n";
}

void ClapTrap::attack(const std::string &target) {
    if (_hitPoints == 0 || _energyPoints == 0) return;
    --_energyPoints;
    std::cout << "ClapTrap <" << _name << "> attacks <" << target << ">, causing "
              << _attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= amount) _hitPoints = 0;
    else _hitPoints -= amount;
    std::cout << "ClapTrap <" << _name << "> takes " << amount << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints == 0 || _energyPoints == 0) return;
    --_energyPoints;
    _hitPoints += amount;
    std::cout << "ClapTrap <" << _name << "> repairs itself for "
              << amount << " hit points!\n";
}
```

**Concepts:**

- **Initialization lists** for efficiency.
- **Resource checking:** ensure positive hit and energy points.
- **Printing** to track lifecycle.

### 4. `main.cpp`

```cpp
#include "ClapTrap.hpp"

int main() {
    ClapTrap ct("CT-One");
    ct.attack("Target-A");
    ct.takeDamage(5);
    ct.beRepaired(3);
    return 0;
}
```

Compile & run:

```bash
cd ex00
make
./ex00
```

---

## Exercise 01: ScavTrap

### 1. Structure

```text
ex01/
├─ ClapTrap.hpp/cpp
├─ ScavTrap.hpp
├─ ScavTrap.cpp
├─ main.cpp
├─ Makefile
```

### 2. `ScavTrap.hpp`

```cpp
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();

    void attack(const std::string &target);
    void guardGate();
};

#endif // SCAVTRAP_HPP
```

### 3. `ScavTrap.cpp`

```cpp
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
    : ClapTrap("default_scav") {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap <" << _name << "> constructed!\n";
}

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap <" << _name << "> constructed!\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    *this = other;
    std::cout << "ScavTrap <" << _name << "> copied!\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap <" << _name << "> destructed!\n";
}

void ScavTrap::attack(const std::string &target) {
    if (_hitPoints == 0 || _energyPoints == 0) return;
    --_energyPoints;
    std::cout << "ScavTrap <" << _name << "> fiercely attacks <"
              << target << ">, dealing " << _attackDamage << " damage!\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap <" << _name << "> is now in Gate keeper mode!\n";
}
```

### 4. Testing

- In `main.cpp`, create both `ClapTrap` and `ScavTrap` objects.
- Show construction/destruction chaining.

```cpp
int main() {
    ScavTrap st("ST-One");
    st.attack("Target-B");
    st.guardGate();
    return 0;
}
```

---

## Exercise 02: FragTrap

### 1. `FragTrap.hpp`

```cpp
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    ~FragTrap();

    void highFivesGuys();
};

#endif // FRAGTRAP_HPP
```

### 2. `FragTrap.cpp`

```cpp
#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
    : ClapTrap("default_frag") {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap <" << _name << "> constructed!\n";
}

FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap <" << _name << "> constructed!\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    *this = other;
    std::cout << "FragTrap <" << _name << "> copied!\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap <" << _name << "> destructed!\n";
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap <" << _name << "> requests a positive high five!\n";
}
```

### 3. Tests

```cpp
int main() {
    FragTrap ft("FT-One");
    ft.attack("Target-C");
    ft.highFivesGuys();
    return 0;
}
```

---

## Exercise 03: DiamondTrap

### 1. `DiamondTrap.hpp`

```cpp
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string _name; // own name, same identifier as in ClapTrap

public:
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap &operator=(const DiamondTrap &other);
    ~DiamondTrap();

    using ScavTrap::attack;         // resolve ambiguity: use ScavTrap's attack
    void whoAmI();                  // reveal both names
};

#endif // DIAMONDTRAP_HPP
```

### 2. `DiamondTrap.cpp`

```cpp
#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap <" << _name << "> constructed!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
    *this = other;
    std::cout << "DiamondTrap <" << _name << "> copied!\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap <" << _name << "> destructed!\n";
}

void DiamondTrap::whoAmI() {
    std::cout << "I am <" << _name << "> and my ClapTrap name is <"
              << ClapTrap::_name << ">!\n";
}
```

### 3. Testing

```cpp
int main() {
    DiamondTrap dt("DT-One");
    dt.attack("Target-D");
    dt.whoAmI();
    dt.highFivesGuys();
    dt.guardGate();
    return 0;
}
```

---

## Submission & Peer-Evaluation

- Ensure each directory (`ex00`–`ex03`) contains **only** the required files.
- Run `make fclean && make` and verify no errors/warnings.
- Peer-evaluate another student's code, focusing on class design, OCF, and clean inheritance chains.

Good luck, and may your ClapTraps never run out of energy!"

```
```
