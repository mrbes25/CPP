/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:51:32 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/08 11:51:38 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Same as before in ex00 ===" << std::endl;
	ClapTrap ct("CT-One");
	ct.attack("Target-A");
	ct.takeDamage(4);
	ct.beRepaired(3);
	std::cout << "\n\n=== New ScavTrap funcitonalitys ===" << std::endl;
	ScavTrap st("ST-One");
	st.attack("Target-B");
	st.guardGate();
	std::cout << "\n\n=== New ScavTrap funcitonalitys ===" << std::endl;
	FragTrap ft("FT-One");
	ft.attack("Target-C");
	ft.highFiveGuys();
	return 0;
}
