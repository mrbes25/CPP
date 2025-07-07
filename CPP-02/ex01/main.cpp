/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:09:02 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/07 13:09:21 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
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

*/
