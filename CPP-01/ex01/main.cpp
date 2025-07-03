/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:58:33 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 11:00:40 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    std::cout << "=== Creating Zombie Horde ===" << std::endl;

    int hordeSize = 5;
    Zombie* horde = zombieHorde(hordeSize, "HordeMember");

    if (horde == NULL) {
        std::cout << "Failed to create horde!" << std::endl;
        return 1;
    }

    std::cout << "\n=== Horde Announcement ===" << std::endl;
    for (int i = 0; i < hordeSize; i++) {
        std::cout << "Zombie " << i << ": ";
        horde[i].announce();
    }

    std::cout << "\n=== Destroying Horde ===" << std::endl;
    delete[] horde;// Use delete[] for arrays, not delete

    std::cout << "\n=== Testing edge cases ===" << std::endl;
    Zombie* emptyHorde = zombieHorde(0, "ShouldFail");
    if (emptyHorde == NULL) {
        std::cout << "Correctly handled invalid horde size" << std::endl;
    }

    return 0;
}




// Never mix `new`/`delete` with `new[]`/`delete[]`** - this causes
//undefined behavior

// The default constructor is called for each array element

// You must set names after allocation since you can't pass
// constructor parameters to `new[]`
