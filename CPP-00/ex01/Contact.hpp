/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:20:30 by bschmid           #+#    #+#             */
/*   Updated: 2025/06/30 18:20:31 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip> // For formatting output


// The contact class represents a single contact in the phonebook
class Contact {
	// Private section: data that can only be accessed through public methods
	// This is a main concept of "encapsulation" in oop
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	// Public section, which can be accessed form outside the class (not only though the class)
	public:
		// Constructor inits a new Contact object
		Contact();
		// Deconstructor called when the Contact object is destroyed
		~Contact();

		// setters (Setter Methods) sets/modifys the private attributes
		void setFirstName(const std::string& firstName);
		void setLastName(const std::string& lastName);
		void setNickName(const std::string& nickName);
		void setPhoneNumber(const std::string& phoneNumber);
		void setDarkestSecret(const std::string& darkestSecret);

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

#endif
