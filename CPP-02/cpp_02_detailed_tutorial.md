# CPP Module 02: Ad-hoc Polymorphism, Operator Overloading, and Orthodox Canonical Class Form

This comprehensive tutorial explores **Module 02** of the 42 C++ curriculum, focusing on fixed-point numbers, operator overloading, and orthodox canonical class form. This guide provides in-depth explanations, detailed code examples, and step-by-step instructions for each exercise.

---

## 📚 Core Concepts

### Fixed-Point Numbers

Fixed-point arithmetic represents real numbers with a fixed number of digits after the decimal point. Unlike floating-point numbers, fixed-point numbers:
- Have constant precision
- Are more predictable in terms of rounding errors
- Can be implemented using integer arithmetic
- Are particularly useful in environments without floating-point hardware

In our implementation, we represent a fixed-point number as:
```
raw_value = real_number * 2^fractional_bits
```

For example, with 8 fractional bits:
- 1.5 becomes: 1.5 * 2^8 = 1.5 * 256 = 384
- 5.0 becomes: 5.0 * 2^8 = 5.0 * 256 = 1280

### Orthodox Canonical Class Form (Rule of Three)

Every C++ class you create should implement the following special member functions:

1. **Default Constructor** - Creates an object with default values
2. **Copy Constructor** - Creates a new object as a copy of an existing one
3. **Copy Assignment Operator** - Assigns the contents of one object to another
4. **Destructor** - Cleans up resources when an object is destroyed

This canonical form ensures proper resource management and prevents memory leaks or undefined behavior.

### Operator Overloading

C++ allows you to redefine operators for custom types, enabling more intuitive code:

```cpp
Fixed a(5.0f);
Fixed b(2.0f);
Fixed c = a + b;  // Using an overloaded '+' operator
```

---

## 📦 Exercise 00: My First Class (Fixed-Point Number)

### Goal

Implement a basic `Fixed` class that stores a fixed-point number with 8 fractional bits.

### Detailed Implementation

#### 1. Class Definition (Fixed.hpp)

```cpp
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _rawValue;                 // The raw fixed-point value
    static const int _fractBits = 8; // Number of fractional bits (always 8)

public:
    // Orthodox Canonical Form
    Fixed(void);                    // Default constructor
    Fixed(const Fixed& src);        // Copy constructor
    Fixed& operator=(const Fixed& rhs); // Copy assignment operator
    ~Fixed(void);                   // Destructor

    // Accessors
    int getRawBits(void) const;     // Get the raw value
    void setRawBits(int const raw); // Set the raw value
};

#endif
```

#### 2. Implementation (Fixed.cpp)

```cpp
#include "Fixed.hpp"

// Default constructor initializes to 0
Fixed::Fixed(void) : _rawValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src; // Use the assignment operator
}

// Assignment operator
Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) { // Check for self-assignment
        this->_rawValue = rhs.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// Get the raw fixed-point value
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawValue;
}

// Set the raw fixed-point value
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawValue = raw;
}
```

#### 3. Testing (main.cpp)

```cpp
#include "Fixed.hpp"
#include <iostream>

int main(void) {
    Fixed a;        // Default constructor
    Fixed b(a);     // Copy constructor
    Fixed c;        // Default constructor

    c = b;          // Assignment operator

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
```

#### Key Points to Understand

- `_rawValue` stores the actual fixed-point number (scaled by 2^8)
- `_fractBits` is a static constant set to 8 bits
- The copy constructor uses the assignment operator to avoid code duplication
- The assignment operator checks for self-assignment to prevent issues
- All methods print messages to help visualize which ones are being called

---

## 📦 Exercise 01: Towards a More Useful Fixed-Point Class

### Goal

Extend the Fixed class to support:
- Conversion from/to integers and floating-point numbers
- Output of the value using the insertion (`<<`) operator

### Detailed Implementation

#### 1. Updated Class Definition (Fixed.hpp)

```cpp
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath> // For roundf()

class Fixed {
private:
    int _rawValue;                 // The raw fixed-point value
    static const int _fractBits = 8; // Number of fractional bits

public:
    // Orthodox Canonical Form
    Fixed(void);                    // Default constructor
    Fixed(const Fixed& src);        // Copy constructor
    Fixed& operator=(const Fixed& rhs); // Copy assignment operator
    ~Fixed(void);                   // Destructor

    // New constructors for conversion
    explicit Fixed(int const i);    // From integer
    explicit Fixed(float const f);  // From floating-point

    // Conversion methods
    float toFloat(void) const;      // Convert to float
    int toInt(void) const;          // Convert to int

    // Accessors
    int getRawBits(void) const;     // Get the raw value
    void setRawBits(int const raw); // Set the raw value
};

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
```

#### 2. Implementation (Fixed.cpp)

```cpp
#include "Fixed.hpp"

// Default constructor initializes to 0
Fixed::Fixed(void) : _rawValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src; // Use the assignment operator
}

// Assignment operator
Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) { // Check for self-assignment
        this->_rawValue = rhs.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// Int constructor - scales integer to fixed-point
Fixed::Fixed(int const i) {
    _rawValue = i << _fractBits; // Multiply by 2^_fractBits
    std::cout << "Int constructor called" << std::endl;
}

// Float constructor - scales float to fixed-point
Fixed::Fixed(float const f) {
    _rawValue = roundf(f * (1 << _fractBits)); // Multiply by 2^_fractBits and round
    std::cout << "Float constructor called" << std::endl;
}

// Convert to float
float Fixed::toFloat(void) const {
    return (float)_rawValue / (1 << _fractBits); // Divide by 2^_fractBits
}

// Convert to int
int Fixed::toInt(void) const {
    return _rawValue >> _fractBits; // Divide by 2^_fractBits (integer division)
}

// Get the raw fixed-point value
int Fixed::getRawBits(void) const {
    return this->_rawValue;
}

// Set the raw fixed-point value
void Fixed::setRawBits(int const raw) {
    this->_rawValue = raw;
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
```

#### 3. Testing (main.cpp)

```cpp
#include "Fixed.hpp"
#include <iostream>

int main(void) {
    Fixed a;                // Default constructor
    Fixed const b(10);      // Int constructor
    Fixed const c(42.42f);  // Float constructor
    Fixed const d(b);       // Copy constructor

    a = Fixed(1234.4321f);  // Float constructor then assignment operator

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
```

#### Key Points to Understand

1. **Integer to Fixed-Point Conversion**:
   - `i << _fractBits` shifts the integer value left by 8 bits
   - This is equivalent to multiplying by 2^8 (or 256)
   - Example: 10 becomes 10 * 256 = 2560

2. **Float to Fixed-Point Conversion**:
   - `roundf(f * (1 << _fractBits))` multiplies the float by 2^8 and rounds to nearest integer
   - `roundf()` ensures proper rounding (from cmath)
   - Example: 42.42f becomes round(42.42 * 256) = round(10859.52) = 10860

3. **Fixed-Point to Float Conversion**:
   - `(float)_rawValue / (1 << _fractBits)` divides the raw value by 2^8
   - Example: 10860 / 256 = 42.42...

4. **Fixed-Point to Integer Conversion**:
   - `_rawValue >> _fractBits` shifts the raw value right by 8 bits
   - This is equivalent to integer division by 2^8 (256)
   - Example: 10860 >> 8 = 42 (truncating the fractional part)

5. **Stream Insertion Operator**:
   - Defined as a free function (not a member)
   - Uses `toFloat()` to display the decimal value
   - Returns the stream reference for chaining

---

## 📦 Exercise 02: Now We're Talking

### Goal

Add comprehensive operator overloading to the Fixed class:
- Comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`
- Arithmetic operators: `+`, `-`, `*`, `/`
- Increment/decrement operators: `++`, `--` (both prefix and postfix)
- Static min/max functions

### Detailed Implementation

#### 1. Updated Class Definition (Fixed.hpp)

```cpp
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath> // For roundf()

class Fixed {
private:
    int _rawValue;                 // The raw fixed-point value
    static const int _fractBits = 8; // Number of fractional bits

public:
    // Orthodox Canonical Form
    Fixed(void);                    // Default constructor
    Fixed(const Fixed& src);        // Copy constructor
    Fixed& operator=(const Fixed& rhs); // Copy assignment operator
    ~Fixed(void);                   // Destructor

    // Constructors for conversion
    explicit Fixed(int const i);    // From integer
    explicit Fixed(float const f);  // From floating-point

    // Comparison operators
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    // Increment/decrement operators
    Fixed& operator++();    // Prefix increment
    Fixed operator++(int);  // Postfix increment
    Fixed& operator--();    // Prefix decrement
    Fixed operator--(int);  // Postfix decrement

    // Min/max functions
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    // Conversion methods
    float toFloat(void) const;      // Convert to float
    int toInt(void) const;          // Convert to int

    // Accessors
    int getRawBits(void) const;     // Get the raw value
    void setRawBits(int const raw); // Set the raw value
};

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
```

#### 2. Implementation (Fixed.cpp)

This would include all previous functions plus:

```cpp
// Comparison operators
bool Fixed::operator>(const Fixed& rhs) const {
    return this->_rawValue > rhs._rawValue;
}

bool Fixed::operator<(const Fixed& rhs) const {
    return this->_rawValue < rhs._rawValue;
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return this->_rawValue >= rhs._rawValue;
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return this->_rawValue <= rhs._rawValue;
}

bool Fixed::operator==(const Fixed& rhs) const {
    return this->_rawValue == rhs._rawValue;
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return this->_rawValue != rhs._rawValue;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(this->_rawValue + rhs._rawValue);
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(this->_rawValue - rhs._rawValue);
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    // Need to be careful with overflow - using float for intermediate calculation
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    // Check for division by zero
    if (rhs._rawValue == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    // Using float for the division to avoid precision issues
    return Fixed(this->toFloat() / rhs.toFloat());
}

// Increment/decrement operators
Fixed& Fixed::operator++() {
    // Prefix increment (++a)
    this->_rawValue += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    // Postfix increment (a++)
    Fixed temp(*this);
    this->_rawValue += 1;
    return temp;
}

Fixed& Fixed::operator--() {
    // Prefix decrement (--a)
    this->_rawValue -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    // Postfix decrement (a--)
    Fixed temp(*this);
    this->_rawValue -= 1;
    return temp;
}

// Min/max functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
```

#### 3. Testing (main.cpp)

```cpp
#include "Fixed.hpp"
#include <iostream>

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    // Additional tests for our new operators
    Fixed c(5);
    Fixed d(2);

    std::cout << "c + d = " << c + d << std::endl;
    std::cout << "c - d = " << c - d << std::endl;
    std::cout << "c * d = " << c * d << std::endl;
    std::cout << "c / d = " << c / d << std::endl;

    std::cout << "c > d: " << (c > d) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;

    return 0;
}
```

#### Key Points to Understand

1. **Comparison Operators**:
   - Directly compare `_rawValue` since we're using the same scale
   - No need for conversion to float

2. **Arithmetic Operators**:
   - Addition/subtraction: simply add/subtract the raw values
   - Multiplication/division: convert to float, perform operation, then convert back to avoid overflow and precision issues

3. **Increment/Decrement**:
   - Prefix (++a): increment and return the reference to the modified object
   - Postfix (a++): make a copy, increment the original, return the copy

4. **Min/Max Functions**:
   - Overloaded for both non-const and const references
   - Use the comparison operators we defined

5. **Careful Implementation Details**:
   - In increment/decrement, we're adding/subtracting 1 to the raw value, which actually represents 1/256 in our fixed-point system
   - For better precision, we could add/subtract (1 << _fractBits) to change by exactly 1.0

---

## 📦 Exercise 03: BSP

### Goal

Create a Point class using Fixed for coordinates, then implement a function to determine if a point is inside a triangle.

### Detailed Implementation

#### 1. Point Class (Point.hpp)

```cpp
#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const _x;  // x-coordinate (const)
    Fixed const _y;  // y-coordinate (const)

public:
    // Orthodox Canonical Form
    Point();                           // Default constructor (0,0)
    Point(const Point& src);           // Copy constructor
    Point& operator=(const Point& rhs); // Assignment operator
    ~Point();                          // Destructor

    // Custom constructor
    Point(float const x, float const y);

    // Accessors
    Fixed getX() const;
    Fixed getY() const;
};

// Helper function for vector operations
Point operator-(const Point& p1, const Point& p2);

// BSP (Binary Space Partitioning) function
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
```

#### 2. Point Implementation (Point.cpp)

```cpp
#include "Point.hpp"

// Default constructor initializes to (0,0)
Point::Point() : _x(0), _y(0) {
}

// Copy constructor
Point::Point(const Point& src) : _x(src._x), _y(src._y) {
}

// Assignment operator - need to handle const members
Point& Point::operator=(const Point& rhs) {
    // Can't modify const members directly
    // This is a bit tricky - typically you'd use a placement new, but for
    // this exercise we'll just leave it as a no-op with a warning
    if (this != &rhs) {
        // Can't modify _x and _y since they're const
        std::cerr << "Warning: Assignment operator called on Point with const members" << std::endl;
    }
    return *this;
}

// Destructor
Point::~Point() {
}

// Custom constructor from float coordinates
Point::Point(float const x, float const y) : _x(x), _y(y) {
}

// Accessors
Fixed Point::getX() const {
    return this->_x;
}

Fixed Point::getY() const {
    return this->_y;
}

// Vector subtraction (for vector operations)
Point operator-(const Point& p1, const Point& p2) {
    return Point(
        p1.getX().toFloat() - p2.getX().toFloat(),
        p1.getY().toFloat() - p2.getY().toFloat()
    );
}
```

#### 3. BSP Implementation (bsp.cpp)

```cpp
#include "Point.hpp"

// Calculate the cross product of two vectors
// For 2D vectors, this gives the signed area of the parallelogram
Fixed cross(Point const& p1, Point const& p2, Point const& p3) {
    return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) -
           (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
}

// Calculate the area of a triangle using cross product
Fixed triangleArea(Point const& a, Point const& b, Point const& c) {
    // Area = |cross_product| / 2, but we can work with the full value
    Fixed cross_product = cross(a, b, c);
    // Take absolute value since area is always positive
    return (cross_product < 0) ? Fixed(0) - cross_product : cross_product;
}

// Check if point p is inside triangle abc
bool bsp(Point const a, Point const b, Point const c, Point const p) {
    // Calculate the area of the main triangle
    Fixed areaABC = triangleArea(a, b, c);

    // If the triangle has zero area, the point can't be inside
    if (areaABC == Fixed(0))
        return false;

    // Calculate areas of three triangles formed with the point
    Fixed areaPAB = triangleArea(p, a, b);
    Fixed areaPBC = triangleArea(p, b, c);
    Fixed areaPCA = triangleArea(p, c, a);

    // If any of these areas is zero, the point lies on an edge
    if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
        return false;

    // The point is inside if the sum of the three areas equals the main area
    // Using a small epsilon to account for floating-point imprecision
    Fixed sumAreas = areaPAB + areaPBC + areaPCA;

    // Check if the areas match (within a small tolerance)
    return (sumAreas == areaABC);
}
```

#### 4. Testing (main.cpp)

```cpp
#include "Point.hpp"
#include <iostream>

int main(void) {
    // Create a triangle
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Test points
    Point inside(5.0f, 5.0f);       // Inside the triangle
    Point outside(20.0f, 20.0f);    // Outside the triangle
    Point edge(5.0f, 0.0f);         // On the edge

    // Check and display results
    std::cout << "Point (5,5) is " << (bsp(a, b, c, inside) ? "inside" : "outside") << std::endl;
    std::cout << "Point (20,20) is " << (bsp(a, b, c, outside) ? "inside" : "outside") << std::endl;
    std::cout << "Point (5,0) is " << (bsp(a, b, c, edge) ? "inside" : "outside") << std::endl;

    return 0;
}
```

#### Key Points to Understand

1. **Point Class Design**:
   - Uses `Fixed` for x and y coordinates
   - Coordinates are `const` to prevent modification after creation
   - Assignment operator has a unique situation with const members

2. **Vector Operations**:
   - Subtraction operator creates a vector between two points
   - Cross product helps determine orientation and area

3. **BSP Algorithm**:
   - Uses the barycentric coordinate method
   - A point is inside a triangle if and only if:
     - The sum of areas of triangles formed with the point equals the main triangle area
     - None of those areas is zero (which would mean the point is on an edge)

4. **Fixed-Point Benefits**:
   - Consistent precision across all calculations
   - Deterministic results (unlike floating-point which can have rounding issues)

---

## 🧠 Advanced Concepts & Tips

### Understanding Fixed-Point Arithmetic

1. **Precision vs. Range Tradeoff**:
   - More fractional bits (higher `_fractBits`) = higher precision but smaller range
   - Fewer fractional bits = lower precision but larger range

2. **Overflow Concerns**:
   - Be cautious with multiplication and division
   - Converting through float helps with precision but might introduce rounding errors

3. **Rounding Strategies**:
   - `roundf()` rounds to nearest integer
   - Other options include truncation, ceiling, floor

### Proper Operator Overloading

1. **Return Type Considerations**:
   - Prefix increment/decrement: return reference for chaining
   - Postfix increment/decrement: return value (copy)
   - Arithmetic operators: return new object
   - Comparison operators: return bool

2. **Const Correctness**:
   - Mark functions as `const` when they don't modify the object
   - Use `const` references for parameters to avoid unnecessary copying

3. **Free Functions vs. Member Functions**:
   - Stream insertion operators should be free functions (non-members)
   - Binary operators that treat both operands equally are often better as free functions

### Memory Management

1. **Rule of Three/Five**:
   - If you need to define one of destructor/copy constructor/assignment operator, you typically need all three
   - Modern C++ extends this to the "Rule of Five" with move semantics

2. **Const Members**:
   - Initialization must happen in initializer list
   - Cannot be modified after construction
   - Creates complications for assignment operator

---

## 📘 Final Thoughts

The fixed-point number implementation provides an excellent foundation for understanding:

1. **Class Design** - How to structure a well-formed class following best practices
2. **Operator Overloading** - How to make custom types behave like built-in types
3. **Initialization vs. Assignment** - The difference and when each is used
4. **Numerical Representation** - How computers represent and manipulate numbers

As you progress, remember that good C++ code is:
- Clear and readable
- Well-encapsulated
- Handles edge cases gracefully
- Uses const-correctness appropriately
- Follows established patterns

This foundation will serve you well in future C++ modules dealing with more complex concepts.

Happy coding!
