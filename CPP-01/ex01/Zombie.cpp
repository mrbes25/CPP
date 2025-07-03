/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:37:09 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 10:45:26 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor -- creates unnamed zombie
Zombie::Zombie() {
	std::cout << "New unnamed Zombie created" << std::endl;
}

Zombie::Zombie(std::string name) : name(name) {
	std::cout << this->name << " has been created!" << std::endl;
}

Zombie::~Zombie() {
	if (this->name.empty())
		std::cout << "An unnamed zombie has been destroyed!" << std::endl;
	else
		std::cout << this->name  << " has been destroyed!" << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
	std::cout << "Zombie has been named: " << this->name << std::endl;
}

void Zombie::announce(void) {
	if (this->name.empty())
		std::cout << "Unnamed zombie: BraiiiiiiinnnzzzZ..." << std::endl;
	else
		std::cout <<this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
