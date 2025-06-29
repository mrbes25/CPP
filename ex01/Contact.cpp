/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:26:20 by bschmid           #+#    #+#             */
/*   Updated: 2025/06/29 18:26:17 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Classes.hpp"


// Constructor - initializes all member variables to empty strings
// Called automatically when a new Contact object is created
Contact::Contact() {
    // In C++98, we initialize members like this in the constructor body
    FirstName = "";
    LastName = "";
    NickName = "";
    PhoneNumber = "";
    DarkestSecret = "";
}

// destructor cleans up when a contact object is destroyed
// for this class there is no manual cleanup needed as std::string handles its own memory :)
Contact::~Contact() {
	// No manual cleanup needed
}

bool Contact::isEmpty() const {
	return FirstName.empty();
}

void Contact::display() const {
    std::cout << "First Name: " << FirstName << std::endl;
    std::cout << "Last Name: " << LastName << std::endl;
    std::cout << "Nickname: " << NickName << std::endl;
    std::cout << "Phone Number: " << PhoneNumber << std::endl;
    std::cout << "Darkest Secret: " << DarkestSecret << std::endl;
}

// Format string for display in table (truncate if too long)
std::string Contact::formatForDisplay(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

// Setter Methods
// they provide controlled access to modify private attributes
// usind setters allows for validation before updating values
void Contact::setFirstName(const std::string& firstName){
	FirstName = firstName;
}

void Contact::setLastName(const std::string& lastName){
	LastName = lastName;
}

void Contact::setNickName(const std::string& nickName){
	NickName = nickName;
}

void Contact::setPhoneNumber(const std::string& phoneNumber){
	PhoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret){
	DarkestSecret = darkestSecret;
}

// GETTER METHODS
// These methods provide read-only access to private attributes
// They're marked const to indicate they don't modify the object's state

std::string Contact::getFirstName() const {
	return FirstName;
}

std::string Contact::getLastName() const {
	return LastName;
}

std::string Contact::getNickName() const {
	return NickName;
}

std::string Contact::getPhoneNumber() const {
	return PhoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return DarkestSecret;
}

