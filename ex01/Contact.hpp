/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:40:31 by ialves-m          #+#    #+#             */
/*   Updated: 2023/11/30 13:50:11 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

class Contact {
	std::string _firstName;		
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
public:
	Contact(){}
	~Contact(){}

	int emptyDetected;

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhoneNumber(void) const;
	std::string getDarkestSecret(void) const;

	void setFirstName(std::string fn);
	void setLastName(std::string ln);
	void setNickname(std::string nn);
	void setPhoneNumber(std::string pn);
	void setDarkestSecret(std::string ds);
};

#endif
