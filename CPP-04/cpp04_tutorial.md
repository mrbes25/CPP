# cpp04 Module Tutorial

This comprehensive tutorial covers **Module 04** (cpp04) of the 42 C++ curriculum. It explains the goals for each exercise, the C++ concepts you need, and provides step-by-step code ideas and explanations—without giving away full solutions.

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

## 📦 Exercise 00: Polymorphism & Abstract Classes

### Goal
- Practice polymorphism with abstract base classes and derived types.
- Implement a base class (e.g., `Animal`) and derived classes (e.g., `Dog`, `Cat`).

### Key Concepts
- **Abstract class:**
  ```cpp
  class Animal {
  public:
      virtual ~Animal();
      virtual void makeSound() const = 0; // pure virtual
      // ...
  };
  ```
- **Derived classes:**
  ```cpp
  class Dog : public Animal {
  public:
      void makeSound() const;
      // ...
  };
  ```
- **Polymorphism:**
  Use base class pointers to call overridden methods:
  ```cpp
  Animal* a = new Dog();
  a->makeSound(); // Calls Dog's version
  delete a;
  ```

### Step by Step
1. **Create abstract base class** with at least one pure virtual function.
2. **Create derived classes** that implement the pure virtual function.
3. **Test** by creating base class pointers to derived objects and calling virtual methods.

---

## 📦 Exercise 01: Deep Copy & Dynamic Memory (Again)

### Goal
- Add a dynamically allocated member (e.g., `Brain`) to derived classes.
- Ensure deep copy semantics.

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

## 📦 Exercise 02: Polymorphic Arrays & Memory Leaks

### Goal
- Create an array of base class pointers, fill it with derived objects, and ensure proper destruction.

### Key Concepts
- **Array of pointers:**
  ```cpp
  Animal* animals[10];
  for (int i = 0; i < 5; ++i) animals[i] = new Dog();
  for (int i = 5; i < 10; ++i) animals[i] = new Cat();
  // ...
  for (int i = 0; i < 10; ++i) delete animals[i];
  ```
- **Virtual destructors:**
  Ensures the correct destructor is called for each object.
- **Memory leak checks:**
  Use tools like `valgrind` to check for leaks.

### Step by Step
1. **Create an array of base class pointers.**
2. **Fill with derived objects.**
3. **Delete all objects via base class pointers.**
4. **Check for memory leaks.**

---

## 📦 Exercise 03: Wrong Implementation & Why Virtual Matters

### Goal
- Show what happens if you forget to make destructors virtual.
- Implement a `WrongAnimal`/`WrongCat` hierarchy without virtual destructors or methods.

### Key Concepts
- **No virtual destructor:**
  ```cpp
  class WrongAnimal {
  public:
      ~WrongAnimal(); // Not virtual!
      void makeSound() const;
  };
  class WrongCat : public WrongAnimal {
  public:
      void makeSound() const;
  };
  ```
- **Polymorphism fails:**
  Deleting a derived object via a base pointer will not call the derived destructor.

### Step by Step
1. **Implement `WrongAnimal` and `WrongCat`** without virtual methods.
2. **Test** by creating a base pointer to a derived object and deleting it.
3. **Observe** that the derived destructor is not called.

---

## 🎯 Tips & Best Practices

- Always use `virtual` destructors in base classes.
- Use `const` correctness for methods that don't modify state.
- Prefer smart pointers (if allowed) to manage dynamic memory.
- Test each feature incrementally.
- Use debug prints to trace object lifecycles and memory management.
- Use tools like `valgrind` to check for memory leaks.

Happy coding! :dog: :cat: :brain:
