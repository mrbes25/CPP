/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:44:44 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/02 12:47:41 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor inits the zombie with a name
Zombie::Zombie(std::string name) : name(name) {
	std::cout << this->name << " has been created!" << std::endl;
}

// Destructor called when zombie is destroyed
Zombie::~Zombie() {
	std::cout << this->name  << " has been destroyed!" << std::endl;
}


// Announce function - zombie introduces itself
void Zombie::announce(void) {
	std::cout <<this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
