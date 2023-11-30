/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:40:28 by ialves-m          #+#    #+#             */
/*   Updated: 2023/11/30 13:52:10 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string	Contact::getFirstName(void) const{
	return this->_firstName;	
}

std::string	Contact::getLastName(void) const{
	return this->_lastName;	
}

std::string	Contact::getNickname(void) const{
	return this->_nickname;	
}

std::string	Contact::getPhoneNumber(void) const{
	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret(void) const{
	return this->_darkestSecret;
}

void Contact::setFirstName(std::string fn)
{
	this->_firstName = fn;
	return ;
}

void Contact::setLastName(std::string ln)
{
	this->_lastName = ln;
	return ;
}

void Contact::setNickname(std::string nn)
{
	this->_nickname = nn;
	return ;
}

void Contact::setPhoneNumber(std::string pn)
{
	this->_phoneNumber = pn;
	return ;
}

void Contact::setDarkestSecret(std::string ds)
{
	this->_darkestSecret = ds;
	return ;
}
