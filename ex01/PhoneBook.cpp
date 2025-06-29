/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:26:47 by bschmid           #+#    #+#             */
/*   Updated: 2025/06/29 18:46:10 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> // for atoi

PhoneBook::PhoneBook() : count(0), oldestIndex(0); {
    // nothing else to initialize
}

PhoneBook::~PhoneBook() {
    // No manual cleanup needed
}

// added a new contact to the phonebook
void PhoneBook::addContact() {
    // Create a temporary contact
    Contact newContact:
    
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
    
    displayContacts();
    
    // Get user's selection
    std::string input = getInput("Enter index to diplay (0-" + std::to_string(count - 1) + "): ");

    int index = std::atoi(input.c_str());
    
    // Validate index
    if (index >= 0 && index < cout) {
        contacts[index].diplay();
    }
    else {
        std::cout << "Invalid index!" << std::endl;
    }
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
    
    // Separator
    std::cout << std::string(43, '-') << std::endl;
    
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

