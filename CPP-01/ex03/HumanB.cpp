/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:59:57 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 13:56:50 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor using initialization list (Required for references)
HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
	std::cout << this->name << " has been created without a weapon " << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
	std::cout << this->name << " has been armed with " << this->weapon->getType() << std::endl;
}

void HumanB::attack() {
	if (this->weapon == NULL) {
		std::cout << this->name << " has no weapon and attacks with their hands!" << std::endl;
	} else {
		std::cout << this->name << " attacks with their " << this->weapon->getType() <<std::endl;
	}
}
