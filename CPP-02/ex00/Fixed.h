/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:30:16 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/06 21:35:46 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _rawValue; // Fixed-point value
    static const int _fractBits = 8; // Number of fractional bits
    
public:
    // Orthodox Canonical Form
    Fixed(void); // Default constructor
    Fixed(const Fixed& src); // copy constructor
    Fixed& operator=(const Fixed& rhs); // Assignment operator
    ~Fixed(void); // Destructor
    
    // Accessors
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif