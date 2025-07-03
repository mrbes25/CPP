/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:07:34 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 10:07:35 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	std::cout << "=== Testing newZombie (HEAP alloc) ===" << std::endl;

	// Create a zombie on HEAP - (manual deletion)
	Zombie* heapZombie = newZombie("Heapigspaengstli");
	heapZombie->announce();
	delete heapZombie;

	std::cout << "\n=== Testing randomChump (STACK alloc) ===" << std::endl;

	// Create zombie on STACK - auto cleanup
	randomChump("SirStackalot");

	return (0);

}




// ==== HEAP vs STACK ----

// HEAP
// newZombie is on the HEAP because it uses a pointer so it can be accessed
// outside of the function scope. It is slower because it needs to reserve
// a whole block in the memory (RAM)

// STACK
// We can use the STACK for the randomChump because it is only neaded inside
// the function scope. Using the STACK is quicker than using the HEAP because
// is will just stack the data in the memory because the size is fixed.
// This makes it easier to manage and access the storage which makes it faster
