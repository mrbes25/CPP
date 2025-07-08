/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:57:01 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/08 09:58:12 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>


// default constructor
ClapTrap::ClapTrap()
: Name("default"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// constructor with name string
ClapTrap::ClapTrap(const std::string &name)
: Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(2)
{
	std::cout << "ClapTrap '" << Name << "' constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap '" << Name << "' copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		Name = other.Name;
		HitPoints = other.HitPoints;
		EnergyPoints = other.EnergyPoints;
		AttackDamage = other.AttackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap '" << Name << "' destructed!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (HitPoints == 0 || EnergyPoints == 0) return;
	--EnergyPoints;
	std::cout << "ClapTrap '" << Name << "' attacks '" << target << "', causing '"
	<< AttackDamage << "' points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPoints <= amount) HitPoints = 0;
	else (HitPoints -= amount);
	std::cout << "ClapTrap '" << Name << "' takes '" << amount << "' points of damage! " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (HitPoints == 0 || EnergyPoints == 0) return;
	--EnergyPoints;
	HitPoints += amount;
	std::cout << "ClapTrap '" << Name << "' repaires '" << amount << "' hit points! " << std::endl;
}
