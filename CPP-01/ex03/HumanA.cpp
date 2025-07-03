/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:54:34 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 12:59:39 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor using initialization list (Required for references)
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
	std::cout << this->name << " has been armed with " << this->weapon.getType() << std::endl;
}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType() <<std::endl;
}
