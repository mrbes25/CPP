/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:35:22 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 09:37:49 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creates a zombie on the HEAP -- has to be deleted manually
Zombie* newZombie(std::string name) {
	Zombie* zombie = new Zombie(name);
	return zombie;
}

