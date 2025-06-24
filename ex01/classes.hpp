/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:43:52 by bschmid           #+#    #+#             */
/*   Updated: 2025/06/24 13:44:17 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_CLASS_HPP
#define MY_CLASS_HPP

#include <iostream>

class Contact{
    // having all the data in private prevents it from being changed unwillingly
    private:
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber;
    std::string DarkestSecret;
    
    public:
    Contact();
    

}



#endif