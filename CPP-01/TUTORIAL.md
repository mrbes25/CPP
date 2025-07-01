# CPP-01 Complete Tutorial - Memory allocation, pointers, references, and the switch statement

## Table of Contents
1. [Overview](#overview)
2. [Key Concepts](#key-concepts)
3. [Exercise by Exercise Guide](#exercise-by-exercise-guide)
4. [Common Pitfalls](#common-pitfalls)
5. [Testing Strategies](#testing-strategies)

## Overview

CPP-01 focuses on understanding C++ memory management, the difference between pointers and references, and proper use of the switch statement. You'll learn when to allocate memory on the stack vs heap, and how to avoid memory leaks.

**Main Learning Goals:**
- Memory allocation (stack vs heap)
- Pointers vs References
- Switch statements
- File I/O
- String manipulation
- Proper memory cleanup

## Key Concepts

### 1. Stack vs Heap Memory

**Stack Memory:**
- Automatic allocation/deallocation
- Fast access
- Limited size
- Local variables, function parameters

**Heap Memory:**
- Manual allocation with `new` / deallocation with `delete`
- Slower access
- Large size available
- Dynamic allocation during runtime

```cpp
// Stack allocation
int stackVar = 42;
std::string stackString = "Hello";

// Heap allocation
int* heapVar = new int(42);
std::string* heapString = new std::string("Hello");

// Don't forget to delete!
delete heapVar;
delete heapString;
```

### 2. Pointers vs References

**Pointers:**
- Can be reassigned
- Can be NULL
- Must be dereferenced with `*`
- Arithmetic operations allowed

**References:**
- Must be initialized when declared
- Cannot be reassigned
- Cannot be NULL
- Automatic dereferencing

```cpp
int value = 42;

// Pointer
int* ptr = &value;
*ptr = 100;  // Dereference to change value

// Reference
int& ref = value;
ref = 200;   // Direct assignment
```

### 3. When to Use Each

- Use **references** for function parameters (when you don't need NULL)
- Use **pointers** when you need to reassign or check for NULL
- Use **stack** for small, short-lived objects
- Use **heap** for large objects or when lifetime extends beyond scope

## Exercise by Exercise Guide

### Ex00: BraiiiiiiinnnzzzZ

**Goal:** Create a Zombie class with proper memory management to understand the difference between stack and heap allocation.

**Detailed Explanation:**
This exercise introduces you to object lifetime management. You'll create two functions that demonstrate when to use stack vs heap allocation:

- `randomChump()`: Creates a zombie that only needs to exist within the function scope
- `newZombie()`: Creates a zombie that needs to persist after the function returns

**Key Learning Points:**
- Stack objects are automatically destroyed when they go out of scope
- Heap objects persist until explicitly deleted
- Understanding when each approach is appropriate

**File Structure:**
```
ex00/
├── Zombie.hpp
├── Zombie.cpp
├── main.cpp
├── newZombie.cpp
├── randomChump.cpp
└── Makefile
```

**Complete Implementation:**

**Zombie.hpp:**
```cpp
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;

public:
    // Constructor
    Zombie(std::string name);

    // Destructor - very important for seeing when objects are destroyed
    ~Zombie();

    // Member function to announce the zombie
    void announce(void);
};

// Function prototypes
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
```

**Zombie.cpp:**
```cpp
#include "Zombie.hpp"

// Constructor - initializes the zombie with a name
Zombie::Zombie(std::string name) : name(name) {
    std::cout << this->name << " has been created!" << std::endl;
}

// Destructor - called when zombie is destroyed
Zombie::~Zombie() {
    std::cout << this->name << " has been destroyed!" << std::endl;
}

// Announce function - zombie introduces itself
void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
```

**newZombie.cpp:**
```cpp
#include "Zombie.hpp"

// Creates a zombie on the HEAP - caller must delete it
Zombie* newZombie(std::string name) {
    Zombie* zombie = new Zombie(name);
    return zombie;
}
```

**randomChump.cpp:**
```cpp
#include "Zombie.hpp"

// Creates a zombie on the STACK - automatically destroyed when function ends
void randomChump(std::string name) {
    Zombie zombie(name);  // Stack allocation
    zombie.announce();
    // Zombie is automatically destroyed here when leaving function scope
}
```

**main.cpp:**
```cpp
#include "Zombie.hpp"

int main() {
    std::cout << "=== Testing newZombie (heap allocation) ===" << std::endl;

    // Create zombie on heap - WE must delete it
    Zombie* heapZombie = newZombie("HeapWalker");
    heapZombie->announce();  // Use -> for pointers
    delete heapZombie;       // CRITICAL: Clean up memory

    std::cout << "\n=== Testing randomChump (stack allocation) ===" << std::endl;

    // Create zombie on stack - automatically cleaned up
    randomChump("StackShambler");

    std::cout << "\n=== End of main ===" << std::endl;
    return 0;
}
```

**Key Observations:**
- Notice the order of destruction messages
- Stack zombies are destroyed immediately when leaving scope
- Heap zombies persist until explicitly deleted
- Forgetting `delete` causes memory leaks

### Ex01: Moar brainz!

**Goal:** Create multiple zombies using dynamic array allocation to understand array memory management.

**Detailed Explanation:**
This exercise builds on Ex00 by introducing dynamic array allocation. You'll learn:
- How to allocate arrays on the heap using `new[]`
- Why you need a default constructor for array allocation
- How to properly deallocate arrays using `delete[]`
- The importance of setting individual array element values after allocation

**Key Learning Points:**
- `new Type[size]` calls the default constructor for each element
- `delete[] array` properly destructs all elements and frees memory
- You cannot directly pass parameters to constructors when using `new[]`
- Arrays allocated with `new[]` must be freed with `delete[]`, not `delete`

**Complete Implementation:**

**Zombie.hpp:**
```cpp
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;

public:
    // Default constructor - REQUIRED for array allocation
    Zombie();

    // Parameterized constructor
    Zombie(std::string name);

    // Destructor
    ~Zombie();

    // Setter for name - needed to name zombies after array allocation
    void setName(std::string name);

    // Announce function
    void announce(void);
};

// Function prototype for creating zombie horde
Zombie* zombieHorde(int N, std::string name);

#endif
```

**Zombie.cpp:**
```cpp
#include "Zombie.hpp"

// Default constructor - creates unnamed zombie
Zombie::Zombie() {
    std::cout << "An unnamed zombie has been created!" << std::endl;
}

// Parameterized constructor
Zombie::Zombie(std::string name) : name(name) {
    std::cout << this->name << " has been created!" << std::endl;
}

// Destructor
Zombie::~Zombie() {
    if (this->name.empty())
        std::cout << "An unnamed zombie has been destroyed!" << std::endl;
    else
        std::cout << this->name << " has been destroyed!" << std::endl;
}

// Set the zombie's name
void Zombie::setName(std::string name) {
    this->name = name;
    std::cout << "Zombie has been named: " << this->name << std::endl;
}

// Announce function
void Zombie::announce(void) {
    if (this->name.empty())
        std::cout << "Unnamed zombie: BraiiiiiiinnnzzzZ..." << std::endl;
    else
        std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
```

**zombieHorde.cpp:**
```cpp
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    // Input validation
    if (N <= 0) {
        std::cout << "Cannot create horde of " << N << " zombies!" << std::endl;
        return NULL;
    }

    std::cout << "Creating horde of " << N << " zombies..." << std::endl;

    // Allocate array of N zombies on heap
    // This calls the default constructor for each zombie
    Zombie* horde = new Zombie[N];

    // Set names for all zombies in the horde
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }

    return horde;
}
```

**main.cpp:**
```cpp
#include "Zombie.hpp"

int main() {
    std::cout << "=== Creating Zombie Horde ===" << std::endl;

    int hordeSize = 5;
    Zombie* horde = zombieHorde(hordeSize, "HordeMember");

    if (horde == NULL) {
        std::cout << "Failed to create horde!" << std::endl;
        return 1;
    }

    std::cout << "\n=== Horde Announcement ===" << std::endl;
    for (int i = 0; i < hordeSize; i++) {
        std::cout << "Zombie " << i << ": ";
        horde[i].announce();
    }

    std::cout << "\n=== Destroying Horde ===" << std::endl;
    // CRITICAL: Use delete[] for arrays, not delete
    delete[] horde;

    std::cout << "\n=== Testing edge cases ===" << std::endl;
    Zombie* emptyHorde = zombieHorde(0, "ShouldFail");
    if (emptyHorde == NULL) {
        std::cout << "Correctly handled invalid horde size" << std::endl;
    }

    return 0;
}
```

**Critical Points:**
- **Never mix `new`/`delete` with `new[]`/`delete[]`** - this causes undefined behavior
- The default constructor is called for each array element
- You must set names after allocation since you can't pass constructor parameters to `new[]`

### Ex02: HI THIS IS BRAIN

**Goal:** Demonstrate the relationship between variables, pointers, and references through memory addresses and values.

**Detailed Explanation:**
This is a simple but crucial exercise that visually demonstrates how pointers and references work at the memory level. You'll see that:
- A variable has a specific memory address
- A pointer stores that address as its value
- A reference is essentially an alias that shares the same address
- All three ways of accessing the data show the same value

**Key Learning Points:**
- Understanding memory addresses and how they relate to variables
- Seeing that references are not separate objects (same address as original)
- Understanding pointer dereferencing
- Visual proof that pointers and references access the same data

**Complete Implementation:**

**main.cpp:**
```cpp
#include <iostream>
#include <string>

int main() {
    // Create a string variable
    std::string str = "HI THIS IS BRAIN";

    // Create a pointer to the string
    std::string* stringPTR = &str;

    // Create a reference to the string
    std::string& stringREF = str;

    std::cout << "=== MEMORY ADDRESSES ===" << std::endl;
    std::cout << "Address of str:        " << &str << std::endl;
    std::cout << "Address stored in PTR: " << stringPTR << std::endl;
    std::cout << "Address of REF:        " << &stringREF << std::endl;

    std::cout << "\n=== VALUES ===" << std::endl;
    std::cout << "Value of str:          " << str << std::endl;
    std::cout << "Value pointed by PTR:  " << *stringPTR << std::endl;
    std::cout << "Value of REF:          " << stringREF << std::endl;

    std::cout << "\n=== ANALYSIS ===" << std::endl;
    std::cout << "All addresses are the same: "
              << ((&str == stringPTR && stringPTR == &stringREF) ? "YES" : "NO")
              << std::endl;
    std::cout << "All values are the same: "
              << ((str == *stringPTR && *stringPTR == stringREF) ? "YES" : "NO")
              << std::endl;

    std::cout << "\n=== MODIFICATION TEST ===" << std::endl;
    std::cout << "Modifying through reference..." << std::endl;
    stringREF = "MODIFIED THROUGH REFERENCE";

    std::cout << "str:     " << str << std::endl;
    std::cout << "*PTR:    " << *stringPTR << std::endl;
    std::cout << "REF:     " << stringREF << std::endl;

    std::cout << "\nModifying through pointer..." << std::endl;
    *stringPTR = "MODIFIED THROUGH POINTER";

    std::cout << "str:     " << str << std::endl;
    std::cout << "*PTR:    " << *stringPTR << std::endl;
    std::cout << "REF:     " << stringREF << std::endl;

    return 0;
}
```

**Expected Output Analysis:**
- All three addresses should be identical
- All three values should be identical
- Modifying through any one of them affects all (they're the same memory location)

**Key Takeaways:**
- References are not pointers - they're aliases
- References cannot be reassigned (they always refer to the same object)
- Pointers can be reassigned to point to different objects
- Both provide access to the same memory location

### Ex03: Unnecessary violence

**Goal:** Understand the practical difference between pointers and references in class design.

**Detailed Explanation:**
This exercise demonstrates a real-world scenario where the choice between pointers and references matters:

- **HumanA** always has a weapon (uses reference) - suitable when the relationship is permanent
- **HumanB** might not have a weapon (uses pointer) - suitable when the relationship is optional

This teaches you when to choose each approach in actual program design.

**Key Learning Points:**
- References must be initialized in the constructor initialization list
- References cannot be changed after initialization
- Pointers can be NULL and should be checked before use
- Pointers can be reassigned to different objects
- Understanding composition vs optional relationships

**File Structure:**
```
ex03/
├── Weapon.hpp
├── Weapon.cpp
├── HumanA.hpp
├── HumanA.cpp
├── HumanB.hpp
├── HumanB.cpp
├── main.cpp
└── Makefile
```

**Complete Implementation:**

**Weapon.hpp:**
```cpp
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
private:
    std::string type;

public:
    // Constructor
    Weapon(std::string type);

    // Getter - returns const reference for efficiency
    const std::string& getType() const;

    // Setter
    void setType(std::string type);
};

#endif
```

**Weapon.cpp:**
```cpp
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {
    std::cout << "Weapon '" << this->type << "' has been created" << std::endl;
}

const std::string& Weapon::getType() const {
    return this->type;
}

void Weapon::setType(std::string type) {
    std::cout << "Weapon type changed from '" << this->type
              << "' to '" << type << "'" << std::endl;
    this->type = type;
}
```

**HumanA.hpp:**
```cpp
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon& weapon;  // Reference - ALWAYS has a weapon

public:
    // Constructor - weapon MUST be provided
    HumanA(std::string name, Weapon& weapon);

    void attack();
};

#endif
```

**HumanA.cpp:**
```cpp
#include "HumanA.hpp"

// Constructor using initialization list (REQUIRED for references)
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
    std::cout << this->name << " has been armed with "
              << this->weapon.getType() << std::endl;
}

void HumanA::attack() {
    std::cout << this->name << " attacks with their "
              << this->weapon.getType() << std::endl;
}
```

**HumanB.hpp:**
```cpp
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon;  // Pointer - MIGHT have a weapon

public:
    // Constructor - no weapon initially
    HumanB(std::string name);

    // Set weapon later
    void setWeapon(Weapon& weapon);

    void attack();
};

#endif
```

**HumanB.cpp:**
```cpp
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
    std::cout << this->name << " has been created without a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
    std::cout << this->name << " has been armed with "
              << this->weapon->getType() << std::endl;
}

void HumanB::attack() {
    if (this->weapon == NULL) {
        std::cout << this->name << " has no weapon and attacks with bare hands!"
                  << std::endl;
    } else {
        std::cout << this->name << " attacks with their "
                  << this->weapon->getType() << std::endl;
    }
}
```

**main.cpp:**
```cpp
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    std::cout << "=== Testing HumanA (always has weapon) ===" << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }

    std::cout << "\n=== Testing HumanB (optional weapon) ===" << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");

        // Jim tries to attack without weapon
        jim.attack();

        // Give Jim a weapon
        jim.setWeapon(club);
        jim.attack();

        // Change weapon type
        club.setType("enhanced war club");
        jim.attack();
    }

    std::cout << "\n=== Testing weapon sharing ===" << std::endl;
    {
        Weapon sharedWeapon = Weapon("legendary sword");

        HumanA warrior("Warrior", sharedWeapon);
        HumanB rogue("Rogue");

        warrior.attack();
        rogue.setWeapon(sharedWeapon);  // Both can use same weapon
        rogue.attack();

        // Changing weapon affects both
        sharedWeapon.setType("cursed blade");
        warrior.attack();
        rogue.attack();
    }

    return 0;
}
```

**Design Analysis:**
- **HumanA**: Use when the relationship is mandatory and permanent
- **HumanB**: Use when the relationship is optional or can change
- Both can share the same weapon object
- Weapon changes affect all users simultaneously

### Ex04: Sed is for losers

**Goal:** Implement a file processing program that replaces all occurrences of a string with another string.

**Detailed Explanation:**
This exercise combines file I/O with string manipulation. You'll create a program that:
1. Takes three arguments: filename, string to find (s1), replacement string (s2)
2. Reads the entire file content
3. Replaces ALL occurrences of s1 with s2
4. Writes the result to a new file with ".replace" extension

**Key Learning Points:**
- File stream operations (`ifstream`, `ofstream`)
- Error handling for file operations
- String searching and replacement algorithms
- Command-line argument processing
- Edge case handling (overlapping strings, empty strings, etc.)

**Complete Implementation:**

**main.cpp:**
```cpp
#include <iostream>
#include <fstream>
#include <string>

// Function to display usage information
void showUsage(const std::string& programName) {
    std::cout << "Usage: " << programName << " <filename> <s1> <s2>" << std::endl;
    std::cout << "  filename: File to process" << std::endl;
    std::cout << "  s1: String to find and replace" << std::endl;
    std::cout << "  s2: Replacement string" << std::endl;
}

// Function to read entire file content
std::string readFile(const std::string& filename) {
    std::ifstream file(filename.c_str());  // .c_str() for C++98 compatibility

    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file '" << filename << "'" << std::endl;
        return "";
    }

    // Read entire file content
    std::string content;
    std::string line;

    // Read line by line and preserve newlines
    while (std::getline(file, line)) {
        content += line;
        if (!file.eof()) {  // Don't add newline after last line
            content += '\n';
        }
    }

    file.close();
    return content;
}

// Function to replace all occurrences of s1 with s2
std::string replaceAll(std::string content, const std::string& s1, const std::string& s2) {
    if (s1.empty()) {
        std::cout << "Warning: Empty search string, no replacement performed" << std::endl;
        return content;
    }

    size_t pos = 0;
    size_t replacements = 0;

    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();  // Move past the replacement
        replacements++;
    }

    std::cout << "Performed " << replacements << " replacements" << std::endl;
    return content;
}

// Function to write content to file
bool writeFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename.c_str());  // .c_str() for C++98 compatibility

    if (!file.is_open()) {
        std::cerr << "Error: Cannot create file '" << filename << "'" << std::endl;
        return false;
    }

    file << content;
    file.close();

    std::cout << "Output written to '" << filename << "'" << std::endl;
    return true;
}

int main(int argc, char* argv[]) {
    // Check argument count
    if (argc != 4) {
        std::cerr << "Error: Wrong number of arguments" << std::endl;
        showUsage(argv[0]);
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::cout << "Processing file: " << filename << std::endl;
    std::cout << "Replacing '" << s1 << "' with '" << s2 << "'" << std::endl;

    // Read file
    std::string content = readFile(filename);
    if (content.empty()) {
        // Could be empty file or error - check if file exists
        std::ifstream testFile(filename.c_str());
        if (!testFile.is_open()) {
            return 1;  // File doesn't exist or can't be opened
        }
        testFile.close();
        std::cout << "File is empty or contains only whitespace" << std::endl;
    }

    // Perform replacement
    std::string result = replaceAll(content, s1, s2);

    // Write result
    std::string outputFilename = filename + ".replace";
    if (!writeFile(outputFilename, result)) {
        return 1;
    }

    return 0;
}
```

**Alternative Implementation (More C++98 Style):**
```cpp
// Alternative approach using stringstream for reading
#include <sstream>

std::string readFileWithStringStream(const std::string& filename) {
    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file '" << filename << "'" << std::endl;
        return "";
    }

    // Use stringstream to read entire file
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}
```

**Testing the Program:**

Create test files:
```bash
echo "Hello world, hello universe, hello everyone" > test.txt
echo "Line 1: hello
Line 2: hello again
Line 3: goodbye" > multiline.txt
echo "" > empty.txt
```

Test cases:
```bash
# Basic replacement
./replace test.txt "hello" "hi"

# Case sensitivity
./replace test.txt "Hello" "Hi"

# Multiple occurrences
./replace multiline.txt "hello" "greetings"

# Empty string replacement (should handle gracefully)
./replace test.txt "" "nothing"

# Non-existent file
./replace nonexistent.txt "a" "b"

# Empty file
./replace empty.txt "a" "b"
```

**Edge Cases to Handle:**
- Empty search string
- Empty replacement string
- File doesn't exist
- Empty file
- Search string appears at beginning/end of file
- Overlapping occurrences
- Binary files (though not required)

### Ex05: Harl 2.0

**Goal:** Create a complaint system using function pointers or member function pointers to avoid long if-else chains.

**Detailed Explanation:**
This exercise introduces you to more advanced C++ concepts like function pointers and demonstrates why they're useful. Instead of writing long if-else chains, you'll use a more elegant solution that's easier to maintain and extend.

The exercise teaches:
- Member function pointers (advanced topic)
- Array-based function dispatch
- Clean code principles
- How to avoid repetitive conditional statements

**Key Learning Points:**
- Member function pointers syntax: `void (ClassName::*functionName)()`
- Function pointer arrays for dispatch tables
- Calling member functions through pointers: `(this->*functionPtr)()`
- Alternative approaches: if-else vs switch vs function pointers

**Complete Implementation:**

**Harl.hpp:**
```cpp
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
private:
    // Private member functions for different complaint levels
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    // Public interface
    void complain(std::string level);
};

#endif
```

**Harl.cpp (Method 1: Function Pointer Array):**
```cpp
#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn't put enough bacon in my burger!" << std::endl;
    std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "This is unacceptable!" << std::endl;
    std::cout << "I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    // Array of level strings
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // Array of member function pointers
    void (Harl::*functions[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // Find matching level and call corresponding function
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*functions[i])();  // Call member function through pointer
            return;
        }
    }

    // If no match found
    std::cout << "Unknown complaint level: " << level << std::endl;
}
```

**Alternative Implementation (Method 2: If-Else Chain):**
```cpp
void Harl::complain(std::string level) {
    if (level == "DEBUG") {
        this->debug();
    } else if (level == "INFO") {
        this->info();
    } else if (level == "WARNING") {
        this->warning();
    } else if (level == "ERROR") {
        this->error();
    } else {
        std::cout << "Unknown complaint level: " << level << std::endl;
    }
}
```

**Alternative Implementation (Method 3: Switch with Helper Function):**
```cpp
// Add to header
enum ComplaintLevel {
    DEBUG_LEVEL,
    INFO_LEVEL,
    WARNING_LEVEL,
    ERROR_LEVEL,
    UNKNOWN_LEVEL
};

ComplaintLevel getComplaintLevel(const std::string& level) {
    if (level == "DEBUG") return DEBUG_LEVEL;
    if (level == "INFO") return INFO_LEVEL;
    if (level == "WARNING") return WARNING_LEVEL;
    if (level == "ERROR") return ERROR_LEVEL;
    return UNKNOWN_LEVEL;
}

void Harl::complain(std::string level) {
    switch (getComplaintLevel(level)) {
        case DEBUG_LEVEL:
            this->debug();
            break;
        case INFO_LEVEL:
            this->info();
            break;
        case WARNING_LEVEL:
            this->warning();
            break;
        case ERROR_LEVEL:
            this->error();
            break;
        default:
            std::cout << "Unknown complaint level: " << level << std::endl;
    }
}
```

**main.cpp:**
```cpp
#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "=== Testing all complaint levels ===" << std::endl;

    std::cout << "\n--- DEBUG ---" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\n--- INFO ---" << std::endl;
    harl.complain("INFO");

    std::cout << "\n--- WARNING ---" << std::endl;
    harl.complain("WARNING");

    std::cout << "\n--- ERROR ---" << std::endl;
    harl.complain("ERROR");

    std::cout << "\n=== Testing invalid levels ===" << std::endl;
    harl.complain("INVALID");
    harl.complain("debug");  // Case sensitive
    harl.complain("");       // Empty string

    std::cout << "\n=== Interactive testing ===" << std::endl;
    std::string level;
    std::cout << "Enter complaint level (or 'quit' to exit): ";
    while (std::getline(std::cin, level) && level != "quit") {
        harl.complain(level);
        std::cout << "\nEnter complaint level (or 'quit' to exit): ";
    }

    return 0;
}
```

**Understanding Member Function Pointers:**

The syntax `void (Harl::*functionName)()` means:
- `void`: return type
- `Harl::`: class name
- `*functionName`: pointer to member function
- `()`: parameter list (empty in this case)

To call: `(this->*functionName)()`
- `this->`: object instance
- `*functionName`: dereference the function pointer
- `()`: call with parameters

### Ex06: Harl filter

**Goal:** Implement a filtering system using switch statement with fall-through behavior to show messages from a specified level and above.

**Detailed Explanation:**
This exercise builds on Ex05 by introducing switch statement fall-through behavior. Unlike Ex05 where you call one specific function, here you want to display all messages from a certain level upward:

- DEBUG: shows DEBUG, INFO, WARNING, ERROR
- INFO: shows INFO, WARNING, ERROR
- WARNING: shows WARNING, ERROR
- ERROR: shows only ERROR

This teaches the important concept of switch fall-through, which is often avoided but has legitimate uses.

**Key Learning Points:**
- Switch statement fall-through behavior
- When fall-through is intentional vs accidental
- Converting strings to enums for switch statements
- Program argument handling
- Cascading behavior implementation

**Complete Implementation:**

**main.cpp:**
```cpp
#include <iostream>
#include <string>

class HarlFilter {
private:
    void debug(void) {
        std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
        std::cout << "I really do!" << std::endl;
    }

    void info(void) {
        std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
        std::cout << "You didn't put enough bacon in my burger!" << std::endl;
        std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
    }

    void warning(void) {
        std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
        std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
    }

    void error(void) {
        std::cout << "This is unacceptable!" << std::endl;
        std::cout << "I want to speak to the manager now." << std::endl;
    }

public:
    enum Level {
        DEBUG_LEVEL,
        INFO_LEVEL,
        WARNING_LEVEL,
        ERROR_LEVEL,
        INVALID_LEVEL
    };

    Level stringToLevel(const std::string& levelStr) {
        if (levelStr == "DEBUG") return DEBUG_LEVEL;
        if (levelStr == "INFO") return INFO_LEVEL;
        if (levelStr == "WARNING") return WARNING_LEVEL;
        if (levelStr == "ERROR") return ERROR_LEVEL;
        return INVALID_LEVEL;
    }

    void complain(const std::string& level) {
        switch (stringToLevel(level)) {
            case DEBUG_LEVEL:
                std::cout << "[ DEBUG ]" << std::endl;
                this->debug();
                std::cout << std::endl;
                // Fall through - this is INTENTIONAL

            case INFO_LEVEL:
                std::cout << "[ INFO ]" << std::endl;
                this->info();
                std::cout << std::endl;
                // Fall through - this is INTENTIONAL

            case WARNING_LEVEL:
                std::cout << "[ WARNING ]" << std::endl;
                this->warning();
                std::cout << std::endl;
                // Fall through - this is INTENTIONAL

            case ERROR_LEVEL:
                std::cout << "[ ERROR ]" << std::endl;
                this->error();
                std::cout << std::endl;
                break;  // End of cascade

            default:
                std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        }
    }
};

void showUsage(const std::string& programName) {
    std::cout << "Usage: " << programName << " <level>" << std::endl;
    std::cout << "Levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
    std::cout << "Shows messages from specified level and above" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Wrong number of arguments" << std::endl;
        showUsage(argv[0]);
        return 1;
    }

    HarlFilter harl;
    std::string level = argv[1];

    std::cout << "Filtering complaints from level: " << level << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    harl.complain(level);

    return 0;
}
```

**Alternative Implementation with Separate Class Files:**

**HarlFilter.hpp:**
```cpp
#ifndef HARLFILTER_HPP
#define HARLFILTER_HPP

#include <iostream>
#include <string>

class HarlFilter {
public:
    enum Level {
        DEBUG_LEVEL,
        INFO_LEVEL,
        WARNING_LEVEL,
        ERROR_LEVEL,
        INVALID_LEVEL
    };

    void complain(const std::string& level);

private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    Level stringToLevel(const std::string& levelStr);
};

#endif
```

**HarlFilter.cpp:**
```cpp
#include "HarlFilter.hpp"

void HarlFilter::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
}

void HarlFilter::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn't put enough bacon in your burger!" << std::endl;
    std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}

void HarlFilter::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void HarlFilter::error(void) {
    std::cout << "This is unacceptable!" << std::endl;
    std::cout << "I want to speak to the manager now." << std::endl;
}

HarlFilter::Level HarlFilter::stringToLevel(const std::string& levelStr) {
    if (levelStr == "DEBUG") return DEBUG_LEVEL;
    if (levelStr == "INFO") return INFO_LEVEL;
    if (levelStr == "WARNING") return WARNING_LEVEL;
    if (levelStr == "ERROR") return ERROR_LEVEL;
    return INVALID_LEVEL;
}

void HarlFilter::complain(const std::string& level) {
    switch (stringToLevel(level)) {
        case DEBUG_LEVEL:
            std::cout << "[ DEBUG ]" << std::endl;
            this->debug();
            std::cout << std::endl;
            // INTENTIONAL fall-through

        case INFO_LEVEL:
            std::cout << "[ INFO ]" << std::endl;
            this->info();
            std::cout << std::endl;
            // INTENTIONAL fall-through

        case WARNING_LEVEL:
            std::cout << "[ WARNING ]" << std::endl;
            this->warning();
            std::cout << std::endl;
            // INTENTIONAL fall-through

        case ERROR_LEVEL:
            std::cout << "[ ERROR ]" << std::endl;
            this->error();
            std::cout << std::endl;
            break;

        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
```

**Testing the Filter:**
```bash
# Test all levels
./harlFilter DEBUG    # Shows all 4 levels
./harlFilter INFO     # Shows INFO, WARNING, ERROR
./harlFilter WARNING  # Shows WARNING, ERROR
./harlFilter ERROR    # Shows only ERROR
./harlFilter INVALID  # Shows default message

# Test edge cases
./harlFilter debug    # Case sensitive - should show default
./harlFilter ""       # Empty string
```

**Understanding Fall-Through:**
The key insight is that **intentional fall-through** is used here. When you enter at DEBUG level, execution continues through all subsequent cases until it hits a `break`. This is exactly what we want - show all messages from the specified level onwards.

**Important Notes:**
- Fall-through is usually a bug, but here it's intentional
- Always comment intentional fall-through to make it clear
- The `break` statement stops the cascade
- Only the ERROR case has a `break` because it's the last level

## Common Pitfalls

### 1. Memory Leaks
```cpp
// BAD - Memory leak
Zombie* zombie = newZombie("Bob");
// Forgot to delete!

// GOOD - Proper cleanup
Zombie* zombie = newZombie("Bob");
// Use zombie...
delete zombie;
```

### 2. Dangling Pointers
```cpp
// BAD - Dangling pointer
Zombie* getZombie() {
    Zombie zombie("Bob");  // Stack allocation
    return &zombie;        // Dangling pointer!
}

// GOOD - Heap allocation or return by value
Zombie* getZombie() {
    return new Zombie("Bob");  // Caller must delete
}
```

### 3. Reference Initialization
```cpp
// BAD - References must be initialized
class HumanA {
    Weapon& weapon;  // Error: reference not initialized
public:
    HumanA(std::string name) {}  // No weapon initialization
};

// GOOD - Initialize in constructor initialization list
class HumanA {
    Weapon& weapon;
public:
    HumanA(std::string name, Weapon& w) : weapon(w) {}
};
```

### 4. File Handling
```cpp
// Always check if file opened successfully
std::ifstream file("filename");
if (!file.is_open()) {
    std::cerr << "Error opening file\n";
    return 1;
}
```

### 5. Array Allocation/Deallocation Mismatch
```cpp
// BAD - Mixing new/delete with new[]/delete[]
Zombie* horde = new Zombie[5];
delete horde;  // WRONG! Should be delete[]

// GOOD - Match allocation/deallocation
Zombie* horde = new Zombie[5];
delete[] horde;  // Correct
```

## Testing Strategies

### 1. Memory Testing
```bash
# Compile with debug flags
g++ -Wall -Wextra -Werror -std=c++98 -g *.cpp

# Test with Valgrind (if available)
valgrind --leak-check=full ./program

# Test edge cases
./program ""           # Empty strings
./program "nonexistent.txt" "a" "b"  # Non-existent files
```

### 2. Test Each Exercise Thoroughly

**Ex00/01:**
- Create zombies on stack and heap
- Verify proper destruction order
- Test with different names

**Ex02:**
- Verify all addresses are the same
- Verify all values are the same

**Ex03:**
- Test HumanA with weapon
- Test HumanB with and without weapon
- Test weapon type changes

**Ex04:**
- Test with various file contents
- Test edge cases (empty files, non-existent files)
- Test replacement at beginning, middle, end of strings

**Ex05/06:**
- Test all log levels
- Test invalid log levels
- Test case sensitivity

## Compilation

Always use these flags for 42 projects:
```bash
g++ -Wall -Wextra -Werror -std=c++98 -o program *.cpp
```

## Summary

CPP-01 teaches fundamental C++ concepts that you'll use throughout the rest of the CPP modules:

1. **Memory Management**: Understanding when and how to use stack vs heap
2. **Pointers vs References**: Knowing which to use in different situations
3. **RAII**: Resource Acquisition Is Initialization - objects manage their own resources
4. **File I/O**: Reading from and writing to files
5. **Switch Statements**: Efficient branching for multiple conditions

Master these concepts, and you'll have a solid foundation for the more advanced topics in later modules!

**Remember**: The key to success in CPP modules is understanding the "why" behind each concept, not just copying code. Make sure you understand each concept before moving to the next exercise.
