/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:34:11 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/07 12:34:29 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
    Fixed a; // Defautl constructor
    Fixed b(a); // copy constructor
    Fixed c;

    c = b; // Assignment operator

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}



// `_rawValue` stores the actual fixed-point number (scaled by 2^8)
// `_fractBits` is a static constant set to 8 bits
// The copy constructor uses the assignment operator to avoid code duplication
// The assignment operator checks for self-assignment to prevent issues
// All methods print messages to help visualize which ones are being called
