/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:02:23 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 11:02:24 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0) {
		std::cout << N << " zombies is not a horde...." << std::endl;
		return NULL;
	}

	std::cout << "Creating horde with" << N << " zombies!" << std::endl;

	// Allocate array of N zombies on HEAP
	// This calls the default constructor for each zombie (why default cons. see .hpp)
	Zombie* horde = new Zombie[N]; // new is the "new" malloc (see what i did there)
	// set names for all zombies
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}

	return horde;
}
