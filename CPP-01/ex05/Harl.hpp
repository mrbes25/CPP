/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:01:21 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 17:01:40 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
	private:
		// Private member functions for different complain levels
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		// Public interface
		void complain(std::string level);
};

#endif
