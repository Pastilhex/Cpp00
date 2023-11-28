/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:40:28 by ialves-m          #+#    #+#             */
/*   Updated: 2023/11/28 15:02:48 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds){
	this->_firstName = fn;
	this->_lastName = ln;
	this->_nickname = nn;
	this->_phoneNumber = pn;
	this->_darkestSecret = ds;
}

Contact::~Contact(){
	return;
}

std::string	Contact::getFirstName(void) const{
	return this->_firstName;	
}

std::string	Contact::getLastName(void) const{
	return this->_lastName;	
}

std::string	Contact::getNickName(void) const{
	return this->_nickname;	
}

std::string	Contact::getPhoneNumber(void) const{
	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret(void) const{
	return this->_darkestSecret;
}

void	Contact::setContact(std::string fname, std::string lname, std::string nname, std::string phnbr, std::string secret){
	this->_firstName = fname;
	this->_lastName = lname;
	this->_nickname = nname;
	this->_phoneNumber = phnbr;
	this->_darkestSecret = secret;
	return;
}
