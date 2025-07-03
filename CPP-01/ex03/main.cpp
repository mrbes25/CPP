/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:58:46 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 13:59:22 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {
	std::cout << "=== Testing HumanA (always has weapon) ===" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	std::cout << "\n=== Testing HumanB (optional weapon) ===" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");

		// Jim tries to attack without a weapon
		jim.attack();

		// Give Jim a weapon
		jim.setWeapon(club);
		jim.attack();

		// Change weapon type
		club.setType("enhanced war club");
		jim.attack();
	}
	return 0;
}


// **HumanA**: Use when the relationship is mandatory and permanent
// **HumanB**: Use when the relationship is optional or can change
// Both can share the same weapon object
// Weapon changes affect all users simultaneously
