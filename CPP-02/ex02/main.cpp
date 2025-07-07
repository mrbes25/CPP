/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:48:27 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/07 14:49:42 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
	Fixed a;                                // Create a Fixed object with value 0 (default constructor)
	Fixed const b(Fixed(5.05f) * Fixed(2)); // Create two temporary Fixed objects, multiply them, store result in b

	std::cout << a << std::endl;    // Prints "0"
	std::cout << ++a << std::endl;  // Increments a by 1/256, then prints (about "0.00390625")
	std::cout << a << std::endl;    // Prints the same value (about "0.00390625")
	std::cout << a++ << std::endl;  // Prints current value, then increments (prints "0.00390625")
	std::cout << a << std::endl;    // Prints new value after increment (about "0.0078125")

	std::cout << b << std::endl;    // Prints the value of b (about "10.1")
	std::cout << Fixed::max(a, b) << std::endl; // Prints the maximum of a and b (which is b, "10.1")
    // Additional tests for our new operators
    Fixed c(5);    // Create Fixed object with value 5 using int constructor
	Fixed d(2);    // Create Fixed object with value 2 using int constructor

    std::cout << "c + d = " << c + d << std::endl; // Prints "c + d = 7"
	std::cout << "c - d = " << c - d << std::endl; // Prints "c - d = 3"
	std::cout << "c * d = " << c * d << std::endl; // Prints "c * d = 10"
	std::cout << "c / d = " << c / d << std::endl; // Prints "c / d = 2.5"

	std::cout << "c > d: " << (c > d) << std::endl;  // Prints "c > d: 1" (true)
	std::cout << "c < d: " << (c < d) << std::endl;  // Prints "c < d: 0" (false)
	std::cout << "c == d: " << (c == d) << std::endl; // Prints "c == d: 0" (false)

    return 0;
}
