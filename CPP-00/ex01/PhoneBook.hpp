/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:20:38 by bschmid           #+#    #+#             */
/*   Updated: 2025/06/30 18:20:39 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip> // For formatting output


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
		std::string getInput(const std::string& prompt) const;
		bool isValidInput(const std::string& input) const;
};

#endif
