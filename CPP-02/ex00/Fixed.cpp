/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:50:37 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/06 22:12:19 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

// Default construcotr inits to 0
Fixed::Fixed(void) : _rawValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy operator
Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy construcor called" << std::endl;
    *this = src; // Use the assignment operator
}

// Assignment operator
Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) { // check for self-assignment
        this->_rawValue = rhs.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

// Get the raw fixed point value
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawValue;
}

// Set the raw fixed point value
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawValue = raw;
}
