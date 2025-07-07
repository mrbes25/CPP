/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:48:54 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/07 13:51:05 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

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
