/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:50:32 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/07 13:06:07 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default construcotr inits to 0
Fixed::Fixed(void) : _rawValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
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

// int constructor scales int to fixed point
Fixed::Fixed(int const i) {
	_rawValue = i << _fractBits; // multiply by 2^ _fractBits
	std::cout << "Int constructor called" << std::endl;
}

// Float constructor scales float to fixed point
Fixed::Fixed(float const f) {
	_rawValue = roundf(f * (1 << _fractBits)); // Multiply be 2^ _fractBits and round
	std::cout << "Float construcor called" << std::endl;
}

// Convert to float
float Fixed::toFloat(void) const {
    return (float)_rawValue / (1 << _fractBits); // Divide by 2^_fractBits
}

// Convert to int
int Fixed::toInt(void) const {
    return _rawValue >> _fractBits; // Divide by 2^_fractBits (integer division)
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

// stream insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

// Without operator<<
// std::cout << "a is ";
// std::cout << a.toFloat(); // Cumbersome
// std::cout << std::endl;

// With operator<<
// std::cout << "a is " << a << std::endl; // Clean and intuitive


