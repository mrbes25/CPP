/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:17:49 by bschmid           #+#    #+#             */
/*   Updated: 2025/06/30 18:18:09 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> // for atoi
#include <sstream>

PhoneBook::PhoneBook() : count(0), oldestIndex(0) {
    // nothing else to initialize
}

PhoneBook::~PhoneBook() {
    // No manual cleanup needed
}

// added a new contact to the phonebook
void PhoneBook::addContact() {
    // Create a temporary contact
    Contact newContact;

    // Get all the required information from user
    std::string input;

    input = getInput("Enter first name: ");
    newContact.setFirstName(input);

    input = getInput("Enter last name: ");
    newContact.setLastName(input);

    input = getInput("Enter nickname: ");
    newContact.setNickName(input);

    input = getInput("Enter phone number: ");
    newContact.setPhoneNumber(input);

    input = getInput("Enter darkest secret: ");
    newContact.setDarkestSecret(input);

    // Add to contacts array (replacing oldest if full)
    contacts[oldestIndex] = newContact;

    // Update indices
    oldestIndex = (oldestIndex + 1) % MAX_CONTACTS;
    if (count < MAX_CONTACTS)
        count++;

    std::cout << "Contact added successfully!" << std::endl;
}

// SEARCH function
void PhoneBook::searchContacts() const {


    if (count == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    // Display all contacts in table format
    displayContacts();

    // Get index from user
    std::string indexInput;
    int index = -1;
    bool validIndex = false;

	while (!validIndex) {
		std::cout << "Enter index to display (0-" << count - 1 << "): ";
		std::getline(std::cin, indexInput);

		if (std::cin.eof()) {
			std::cout << std::endl << "EOF detected. Returning to main menu." << std::endl;
			return;
		}

		// Check if the input is valid (all digits)
		bool isNumeric = true;
		for (size_t i = 0; i < indexInput.length(); i++) {
			if (!std::isdigit(indexInput[i])) {
				isNumeric = false;
				break;
			}
		}

		// Process the input
		if (isNumeric && !indexInput.empty()) {
			index = std::atoi(indexInput.c_str());
			if (index >= 0 && index < count) {
				validIndex = true;
			} else {
				std::cout << "Invalid index! Please try again." << std::endl;
			}
		} else {
			std::cout << "Invalid input! Please enter a number." << std::endl;
		}
	}

    // Display the selected contact
    contacts[index].display();
}

// Display menu options
void PhoneBook::displayMenu() const {
    std::cout << "\n===== PHONEBOOK MENU =====" << std::endl;
    std::cout << "ADD    - Add a new contact" << std::endl;
    std::cout << "SEARCH - Search contacts" << std::endl;
    std::cout << "EXIT   - Exit the program" << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "> ";
}

void PhoneBook::displayContacts() const {
    // Header
    std::cout << std::setw(10) << "INDEX" << "|";
    std::cout << std::setw(10) << "FIRST NAME" << "|";
    std::cout << std::setw(10) << "LAST NAME" << "|";
    std::cout << std::setw(10) << "NICKNAME" << std::endl;

    // Print a separator line
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    // Rows
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << Contact::formatForDisplay(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << Contact::formatForDisplay(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << Contact::formatForDisplay(contacts[i].getNickName()) << std::endl;
    }
}

// Get input from user with validation
std::string PhoneBook::getInput(const std::string& prompt) const {
    std::string input;

    do {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (std::cin.eof()) {
            std::cout << "EOF detected. Exiting program." << std::endl;
            exit(0);
        }

        if (input.empty()) {
            std::cout << "Input cannot be empty. Please try again." << std::endl;
        }
    } while (input.empty());

    return input;
}

// Validate input (can be expanded for specific validation needs)
bool PhoneBook::isValidInput(const std::string& input) const {
    return !input.empty();
}

