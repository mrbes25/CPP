/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:43:18 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/02 12:44:03 by bschmid          ###   ########.fr       */
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
	Zombie(std::string name);

	~Zombie();

	void announce(void);
};
// Function prototypes
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif

