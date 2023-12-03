/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:40:35 by ialves-m          #+#    #+#             */
/*   Updated: 2023/12/03 16:29:09 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
public:
	Contact contacts[8];
	int records;
};

void	viewContact(PhoneBook* myPhoneBook, int index);
void	optionSearch(PhoneBook* myPhoneBook);
void	drawHeader();
void	optionAdd(std::string arg, PhoneBook* myPhoneBook, int currentRegistry, int* registryNumber);
void	menu(void);
int		countRecords(PhoneBook* myPhoneBook);


#endif
