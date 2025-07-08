/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:30:33 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/08 09:50:26 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct("Flaetterewaetter");
	ct.attack("LinkiBacke");
	ct.takeDamage(4);
	ct.beRepaired(3);
	return 0;
}
