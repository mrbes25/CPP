# cpp03 Module Tutorial

This comprehensive tutorial covers **Module 03** (cpp03) of the 42 C++ curriculum. It explains the goals for each exercise, the C++ concepts you need, and provides step-by-step code ideas and explanations—without giving away full solutions.

---

## 📝 Prerequisites & Setup

- **Compiler flags:**
  ```bash
  c++ -Wall -Wextra -Werror -std=c++98
  ```
- **Directory structure:**
  ```text
  ex00/
  ex01/
  ex02/
  ex03/
  ```
- **Rule of Three/Five:**
  Implement the canonical form for every class: default constructor, copy constructor, copy assignment operator, destructor (and move constructor/operator if needed).

---

## 📦 Exercise 00: Orthodox Canonical Form & Inheritance

### Goal

- Practice the Orthodox Canonical Form with inheritance.
- Create a base class and a derived class, each with proper constructors, destructors, and assignment operators.

### Key Concepts

- **Inheritance:**
  ```cpp
  class Animal {
  public:
      Animal();
      Animal(const Animal&);
      Animal& operator=(const Animal&);
      virtual ~Animal();
  };

  class Dog : public Animal {
  public:
      Dog();
      Dog(const Dog&);
      Dog& operator=(const Dog&);
      ~Dog();
  };
  ```
- **Virtual destructor:** Always declare the base class destructor as `virtual` to ensure proper cleanup.
- **Debug prints:** Add prints in each constructor/destructor to trace object lifecycles.

### Step by Step

1. **Create `Animal` base class** with all canonical form methods, and a `type` attribute.
2. **Create `Dog` (and optionally `Cat`) derived class** inheriting from `Animal`.
3. **Implement all methods** in `.cpp` files, printing a message for each.
4. **Test** by creating, copying, assigning, and destroying objects.

---

## 📦 Exercise 01: Virtual Functions & Polymorphism

### Goal

- Use virtual functions to enable polymorphic behavior.
- Add a `makeSound()` method to `Animal` and override it in derived classes.

### Key Concepts

- **Virtual functions:**
  ```cpp
  class Animal {
  public:
      virtual void makeSound() const;
  };
  class Dog : public Animal {
  public:
      void makeSound() const;
  };
  ```
- **Polymorphism:**
  Allows calling the correct method for the actual object type, even via a base class pointer/reference.

### Step by Step

1. **Add `makeSound()` as a virtual method** in `Animal`.
2. **Override `makeSound()`** in `Dog` and `Cat` to print different sounds.
3. **Test** with an array of `Animal*` pointing to `Dog`/`Cat` and call `makeSound()` on each.

---

## 📦 Exercise 02: Deep Copy & Dynamic Memory

### Goal

- Add a `Brain` class as a member of `Dog`/`Cat`.
- Ensure deep copy semantics (each animal has its own `Brain`).

### Key Concepts

- **Composition:**
  ```cpp
  class Brain {
  public:
      std::string ideas[100];
      // Canonical form
  };
  class Dog : public Animal {
  private:
      Brain* brain;
  };
  ```
- **Deep copy:**
  In copy constructor/assignment, allocate a new `Brain` and copy its contents.
- **Destructor:**
  Delete the `Brain` pointer to avoid memory leaks.

### Step by Step

1. **Implement `Brain` class** with canonical form.
2. **Add `Brain* brain` to `Dog`/`Cat`** and manage it in all special member functions.
3. **In copy constructor/assignment,** allocate and copy the `Brain`.
4. **In destructor,** delete the `Brain`.
5. **Test** by copying/assigning animals and checking that their brains are independent.

---

## 📦 Exercise 03: Abstract Classes & Pure Virtual Functions

### Goal

- Make `Animal` an abstract class by adding a pure virtual function.
- Prevent direct instantiation of `Animal`.

### Key Concepts

- **Abstract class:**
  ```cpp
  class Animal {
  public:
      virtual void makeSound() const = 0; // pure virtual
  };
  ```
- **Cannot instantiate:**
  You cannot create an `Animal` object directly.
- **Derived classes** must implement all pure virtual functions.

### Step by Step

1. **Change `makeSound()` in `Animal`** to pure virtual.
2. **Ensure all derived classes** implement `makeSound()`.
3. **Test**: Try to instantiate `Animal` (should fail), but `Dog`/`Cat` should work.

---

## 🎯 Tips & Best Practices

- Always use `virtual` destructors in base classes.
- Use `const` correctness for methods that don't modify state.
- Prefer smart pointers (if allowed) to manage dynamic memory.
- Test each feature incrementally.
- Use debug prints to trace object lifecycles and memory management.

Happy coding! :dog: :cat: :brain:
