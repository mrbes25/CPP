/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:45:25 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 12:48:38 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {
	std::cout << "Weapon " << this->type << " has been created" << std::endl;
}

const std::string& Weapon::getType() const {
	return this->type;
}

void Weapon::setType(std::string type) {
	std::cout <<"Weapon type changed from " << this->type << " to " << type << std::endl;
	this->type = type;
}
