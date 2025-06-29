/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:26:15 by bschmid           #+#    #+#             */
/*   Updated: 2025/06/29 18:54:18 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_CLASS_HPP
#define MY_CLASS_HPP

#include <iostream>
#include <string>
#include <iomanip> // For formatting output


// The contact class represents a single contact in the phonebook
class Contact {
	// Private section: data that can only be accessed through public methods
	// This is a main concept of "encapsulation" in oop
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;

	// Public section, which can be accessed form outside the class (not only though the class)
	public:
		// Constructor inits a new Contact object
		Contact();
		// Deconstructor called when the Contact object is destroyed
		~Contact();

		// setters (Setter Methods) sets/modifys the private attributes
		void setFirstName(const std::string& FirstName);
		void setLastName(const std::string& LastName);
		void setNickName(const std::string& NickName);
		void setPhoneNumber(const std::string& PhoneNumber);
		void setDarkestSecret(const std::string& DarkestSecret);

		// Getters (Getter Methods) access the private attributes
		// marked const because they don't modify the object's state
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;

		// Helper methods
		bool isEmpty() const; // check if the contact has data
		void display() const; // display all fields of this contact

		// Static method to format strings for table display
		static std::string formatForDisplay(const std::string& str);


};

// The phonebook class manages a collection of contact objects
class PhoneBook {
	private:
		static const int MAX_CONTACTS = 8;
		Contact contacts[MAX_CONTACTS];
		int count;
		int oldestIndex;

	public:
		PhoneBook();
		~PhoneBook();

		// main operations
		void addContact();
		void searchContacts() const;
		void displayMenu() const;

	private:
		void displayContacts() const;
		void displayConstact() const;
		std::string getInput(const std::string& prompt) const;
		bool isValidInput(const std::string& input) const;
};



#endif
