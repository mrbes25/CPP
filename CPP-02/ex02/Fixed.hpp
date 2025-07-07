/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:46:50 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/07 13:48:50 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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
