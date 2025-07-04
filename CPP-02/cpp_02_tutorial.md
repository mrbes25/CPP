# cpp02 Module Tutorial

This step-by-step walkthrough covers **Module 02** (cpp02) of the 42 C++ curriculum. It provides goals for each exercise, explains necessary C++ concepts, and offers small illustrative snippets—without revealing complete solutions.

---

## 📝 Prerequisites & Setup

1. **Compiler flags**
   ```bash
   c++ -Wall -Wextra -Werror -std=c++98
   ```
2. **Directory structure**\
   Each exercise should live in its own folder:
   ```text
   ex00/
   ex01/
   ex02/
   ex03/
   ```
3. **Rule of Three (Orthodox Canonical Form)**\
   Every class you write must implement:
   - Default constructor
   - Copy constructor
   - Copy assignment operator
   - Destructor

---

## 📦 Exercise 00: My First Class (Fixed-Point Shell)

### Goal

Implement a `Fixed` class that holds a **fixed-point** value (internally an `int`) and uses a constant fractional-bit count (8 bits).

### Key Concepts

- **Fixed-point arithmetic**\
  Represent a real number `x` as:
  ```text
  raw = x * 2^fractional_bits
  ```
- **Static constant members**
  ```cpp
  class Fixed {
  private:
      int                 _raw;
      static const int    _fractBits = 8;
      // ...
  };
  ```
- **Rule of Three**
  ```cpp
  Fixed();                             // default constructor
  Fixed(Fixed const & other);         // copy constructor
  Fixed & operator=(Fixed const & o); // copy assignment operator
  ~Fixed();                            // destructor
  ```
- **Accessors**
  ```cpp
  int  getRawBits(void) const;
  void setRawBits(int const raw);
  ```

### Step by Step

1. **Header file (**``**)**
   - Declare private `_raw` and `static const _fractBits`.
   - Declare all four special member functions.
   - Declare `getRawBits()` and `setRawBits()`.
2. **Source file (**``**)**
   - Define each constructor/operator/destructor to print a debug message.
   - Initialize `_raw` to 0 in the default constructor.
3. **Test in **``\
   Verify that copy, assignment, and accessor calls print expected messages.

---

## 📦 Exercise 01: Making It Useful

### Goal

Extend the `Fixed` class to:

- Convert to/from `int` and `float`.
- Stream-output its decimal value using `operator<<`.

### New Concepts

- **Overloaded constructors**
  ```cpp
  explicit Fixed(int const i);    // from integer
  explicit Fixed(float const f);  // from float
  ```
  > *Tip:* Mark single-arg constructors `explicit` to prevent unintended implicit conversions.
- **Conversion member functions**
  ```cpp
  float toFloat(void) const;
  int   toInt(void)   const;
  ```
- ``** overload**\
  As a free function so you can do `std::cout << myFixed;`:
  ```cpp
  std::ostream & operator<<(std::ostream & os, Fixed const & f) {
      return os << f.toFloat();
  }
  ```

### Step by Step

1. **Implement **``** constructor**
   ```cpp
   Fixed::Fixed(int const i) {
       _raw = i << _fractBits;  // multiply by 2^_fractBits
       std::cout << "Int constructor called" << std::endl;
   }
   ```
2. **Implement **``** constructor**
   ```cpp
   Fixed::Fixed(float const f) {
       _raw = roundf(f * (1 << _fractBits));
       std::cout << "Float constructor called" << std::endl;
   }
   ```
3. **Implement **``** / **``
   ```cpp
   float Fixed::toFloat(void) const { return _raw / float(1 << _fractBits); }
   int   Fixed::toInt(void)   const { return _raw >> _fractBits; }
   ```
4. **Overload **`` as shown above.
5. **Test** with mixed constructors and check both `toFloat()` output and `toInt()` truncation.

---

## 📦 Exercise 02: Operator Overloading & Helpers

### Goal

Enable full arithmetic, comparison, increment/decrement, and provide `min`/`max` helpers for the `Fixed` class.

### New Concepts

- **Comparison operators**\
  As `const` member functions returning `bool`:
  ```cpp
  bool operator>(Fixed const & rhs) const { return _raw > rhs._raw; }
  // … similarly for <, >=, <=, ==, !=
  ```
- **Arithmetic operators**\
  Return a new `Fixed` by doing raw-value math, e.g.:
  ```cpp
  Fixed operator+(Fixed const & rhs) const {
      Fixed tmp;
      tmp._raw = this->_raw + rhs._raw;
      return tmp;
  }
  ```
- **Pre vs. Post increment**
  ```cpp
  // pre-increment
  Fixed & operator++()   { ++_raw; return *this; }
  // post-increment
  Fixed   operator++(int){ Fixed tmp(*this); _raw++; return tmp; }
  ```
- **Static member functions**
  ```cpp
  static Fixed &       min(Fixed & a, Fixed & b);
  static Fixed const & min(Fixed const & a, Fixed const & b);
  // similarly for max()
  ```

### Step by Step

1. **Add comparison overloads** in `Fixed.hpp` and implement in `.cpp`.
2. **Add arithmetic operators**—keep implementations simple by manipulating `_raw`.
3. **Implement increment/decrement operators**—remember the dummy `int` parameter for post-forms.
4. **Implement **``**/**`` by comparing values and returning the appropriate reference.
5. **Test** thoroughly:
   ```cpp
   Fixed a;
   Fixed const b(Fixed(5.05f) * Fixed(2));
   std::cout << ++a << std::endl;
   std::cout << a++ << std::endl;
   std::cout << Fixed::max(a, b) << std::endl;
   ```

---

## 📦 Exercise 03: BSP (Point in Triangle)

### Goal

Create a `Point` class using your `Fixed` type, then write:

```cpp
bool bsp(Point const a, Point const b, Point const c, Point const p);
```

It should return **true** if **p** lies *strictly* inside triangle **abc**.

### Key Concepts

- **Initializer lists** for `const` members:
  ```cpp
  class Point {
  private:
      Fixed const _x, _y;
  public:
      Point(): _x(0), _y(0) {}
      Point(float x, float y): _x(x), _y(y) {}
      // … rule of three …
  };
  ```
- **Barycentric / area method**:
  1. Compute area of ABC:\
     \(  A = \bigl| (B - A) \times (C - A) \bigr| / 2\)
  2. Compute areas of PAB, PBC, PCA: \(A_1, A_2, A_3\).
  3. If \(A_1 + A_2 + A_3 = A\) **and** none are zero (so P isn’t on an edge), then **inside**.
- **2D cross-product (scalar)**:
  ```cpp
  Fixed cross(Point const & p1, Point const & p2) {
      return p1.getX() * p2.getY() - p1.getY() * p2.getX();
  }
  ```

### Step by Step

1. **Implement **`` with `_x` and `_y` as `const Fixed`, following the Rule of Three.
2. **Vector difference operator**:
   ```cpp
   Point Point::operator-(Point const & rhs) const {
       return Point((x - rhs.x).toFloat(), (y - rhs.y).toFloat());
   }
   ```
3. **Cross-product helper**:
   ```cpp
   Fixed cross(Point const & v1, Point const & v2);
   ```
4. **Implement **``** logic**:
   ```cpp
   Fixed areaABC = cross(b - a, c - a).abs();
   Fixed areaPAB = cross(a - p, b - p).abs();
   // … areaPBC, areaPCA …
   if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
       return false;  // on an edge or vertex
   return (areaPAB + areaPBC + areaPCA) == areaABC;
   ```
5. **Test** with points inside, outside, and on edges.

---

## 🎯 Tips & Best Practices

- Use `explicit` for single-argument constructors to avoid implicit conversions.
- Ensure headers are self-sufficient (include guards, necessary `#include`s).
- Implement logic in `.cpp` files—not inline in headers unless trivial.
- Maintain `const`-correctness (mark methods `const` when they don’t modify state).
- Test incrementally: after each feature, write a small `main()` to verify behavior.
- Use debug prints during development; remove them once functionality is confirmed.

Happy coding, and may your fixed-point math be always precise! \:rocket

