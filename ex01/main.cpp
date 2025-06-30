/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:16:42 by bschmid           #+#    #+#             */
/*   Updated: 2025/06/30 18:16:50 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
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
