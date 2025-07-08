/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:01:37 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/08 11:01:46 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Same as before in ex00 ===" << std::endl;
	ClapTrap ct("CT-One");
	ct.attack("Target-A");
	ct.takeDamage(4);
	ct.beRepaired(3);
	std::cout << "=== New ScavTrap funcitonalitys ===" << std::endl;
	ScavTrap st("ST-One");
	st.attack("Target-B");
	st.guardGate();

	return 0;
}
