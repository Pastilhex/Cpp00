/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:40:31 by ialves-m          #+#    #+#             */
/*   Updated: 2023/11/28 15:01:41 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <cstring>

class Contact {
private:
	std::string _firstName;		
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
	~Contact();

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickName(void) const;
	std::string getPhoneNumber(void) const;
	std::string getDarkestSecret(void) const;
	
	void setContact(std::string fname, std::string lname, std::string nname, std::string phnbr, std::string secret);

};

#endif
