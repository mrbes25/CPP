/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:20:53 by bschmid           #+#    #+#             */
/*   Updated: 2025/06/30 18:20:54 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"


// Constructor - initializes all member variables to empty strings
// Called automatically when a new Contact object is created
Contact::Contact() {
    // In C++98, we initialize members like this in the constructor body
    firstName = "";
    lastName = "";
    nickName = "";
    phoneNumber = "";
    darkestSecret = "";
}

// destructor cleans up when a contact object is destroyed
// for this class there is no manual cleanup needed as std::string handles its own memory :)
Contact::~Contact() {
	// No manual cleanup needed
}

bool Contact::isEmpty() const {
	return firstName.empty();
}

void Contact::display() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
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
	this->firstName = firstName;
}

void Contact::setLastName(const std::string& lastName){
	this->lastName = lastName;
}

void Contact::setNickName(const std::string& nickName){
	this->nickName = nickName;
}

void Contact::setPhoneNumber(const std::string& phoneNumber){
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret){
	this->darkestSecret = darkestSecret;
}

// GETTER METHODS
// These methods provide read-only access to private attributes
// They're marked const to indicate they don't modify the object's state

std::string Contact::getFirstName() const {
	return firstName;
}

std::string Contact::getLastName() const {
	return lastName;
}

std::string Contact::getNickName() const {
	return nickName;
}

std::string Contact::getPhoneNumber() const {
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return darkestSecret;
}

