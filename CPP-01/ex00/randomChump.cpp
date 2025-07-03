/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:37:55 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 09:39:20 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

// Creates a zombie on the STACK -- automatically destroyed when func ends
void randomChump(std::string name) {
	Zombie zombie(name);
	zombie.announce();
	// Zombie is autpmaticaally destoryed here whem leaving the function
}
