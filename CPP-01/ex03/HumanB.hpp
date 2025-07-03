/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:00:32 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 13:00:33 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon* weapon; // Pointer Might have (access) a weapon

	public:
		// Constructor -- doesn't need a weapon initially
		HumanB(std::string name);

		// Set weapon later
		void setWeapon(Weapon& weapon);

		void attack();
};

#endif
