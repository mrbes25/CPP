/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:56:18 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 17:56:19 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


int main() {
	// create string variable
	std::string str = "HI THIS IS BRAIN";

	// create a pointer to the string
	std::string* stringPTR = &str;

	// create a reference to the string
	std::string& stringREF = str;

	std::cout << "=== MEMORY ADRESSES ===" << std::endl;
	std::cout << "Address of str:        " << &str << std::endl;
    std::cout << "Address stored in PTR: " << stringPTR << std::endl;
    std::cout << "Address of REF:        " << &stringREF << std::endl;

    std::cout << "\n=== VALUES ===" << std::endl;
    std::cout << "Value of str:          " << str << std::endl;
    std::cout << "Value pointed by PTR:  " << *stringPTR << std::endl;
    std::cout << "Value of REF:          " << stringREF << std::endl;

    return 0;
}

// References are not pointers - they're ALIASES
// References cannot be reassigned (they always refer to the same object)
// Pointers can be reassigned to point to different objects
// Both provide access to the same memory location
