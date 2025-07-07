/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:07:39 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/07 13:07:48 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _rawValue; // raw Fixed-point value
    static const int _fractBits = 8; // Number of fractional bits

public:
    // Orthodox Canonical Form
    Fixed(void); // Default constructor
    Fixed(const Fixed& src); // copy constructor
    Fixed& operator=(const Fixed& rhs); // copy assignment operator
    ~Fixed(void); // Destructor


	// The explicit keyword prevents implicit type conversions from happening automatically
	// New constructors for conversion
	explicit Fixed(int const i); // from int
	explicit Fixed(float const f); // from floating point

	// Conversion methods
	float toFloat(void) const; // convert to float
	int toInt(void) const; // convert to int

    // Accessors
    int getRawBits(void) const; // get raw value
    void setRawBits(int const raw); // set raw value
};

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
