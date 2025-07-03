/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:00:08 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 17:00:15 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "=== Testing all complaint levels ===" << std::endl;

    std::cout << "\n--- DEBUG ---" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\n--- INFO ---" << std::endl;
    harl.complain("INFO");

    std::cout << "\n--- WARNING ---" << std::endl;
    harl.complain("WARNING");

    std::cout << "\n--- ERROR ---" << std::endl;
    harl.complain("ERROR");

    std::cout << "\n=== Testing invalid levels ===" << std::endl;
    harl.complain("INVALID");
    harl.complain("debug");  // Case sensitive
    harl.complain("");       // Empty string

	return 0;
}
