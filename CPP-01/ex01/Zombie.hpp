/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:46:59 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 10:36:10 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
	std::string name;

public:
	// Default constructor -- REQUIRED for array allocation ***
	Zombie();

	Zombie(std::string name);

	~Zombie();

	void setName(std::string name);

	void announce(void);
};

// Function prototypes
Zombie* zombieHorde(int N, std::string name);

#endif

// ***
// Why it needs a default constructor
// when initializing an array it needs to call a default constructor (no arguments)
// if there are only constructors with arguments the initialization of the array
// would not know which arguments to pass and would cause a compilation error

