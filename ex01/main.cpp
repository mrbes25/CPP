/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:46:33 by bschmid           #+#    #+#             */
/*   Updated: 2025/06/29 18:52:47 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <iostream>
#include <string>

int main() {
    // Create phonebook object
    PhoneBook phonebook;
    std::string command;
    
    std::cout << "Welcome to PhoneBook!" << std::endl;
    
    // Main program loop
    while (true) {
        // Display menu and get command
        phonebook.displayMenu();
        std::getline(std::cin, command);
        
        // Check for EOF
        if (std::cin.eof()) {
            std::cout << "EOF detected. Exiting program." << std::endl;
            break;
        }
        
        // Process command
        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContacts();
        } else if (command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
    
    return 0;
}