/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:48:57 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 12:51:52 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		std::string name;
		Weapon& weapon; // this is a reference (has allways (access) to the weapon)

	public:
		// Constructor -- weapon must be provided to compile correctly
		HumanA(std::string name, Weapon& weapon);

		void attack();
};

#endif
