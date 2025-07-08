/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:53:46 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/08 11:54:06 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
: ClapTrap("default_scav")
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap '" << Name << "' constructed!\n";
}

ScavTrap::ScavTrap(const std::string &name)
: ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap '" << Name << "' constructed!\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "ScavTrap '" << Name << "' copied!\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap '" << Name << "' destructed!\n";
}

void ScavTrap::attack(const std::string &target)
{
	if (HitPoints == 0 || EnergyPoints == 0) return;
	--EnergyPoints;
	std::cout << "ScavTrap '" << Name << "' attacks *different than ClapTrap*'"
	<< target << "', dealing '" << AttackDamage << "' damage!" << std::endl;
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap '" << Name << "' is now in Gate keeper mode!" << std::endl;
}
