/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:15:01 by ialves-m          #+#    #+#             */
/*   Updated: 2023/12/03 19:12:44 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void	menu(void)
{
	system("clear");
	std::cout << "      __        __        ___  __   __   __       " << std::endl;
	std::cout << "     |__) |__| /  \\ |\\ | |__  |__) /  \\ /  \\ |__/ " << std::endl;
	std::cout << "     |    |  | \\__/ | \\| |___ |__) \\__/ \\__/ |  \\ " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "              ~ ADD - SEARCH - EXIT ~           \n" << std::endl;
}

void	optionAdd(std::string arg, PhoneBook* myPhoneBook, int currentRegistry, int* registryNumber)
{
	std::cout << std::endl;

	do {
		std::cout << " Enter your first name: ";
		std::getline(std::cin, arg);
	} while (arg.empty());
	myPhoneBook->contacts[currentRegistry].setFirstName(arg);

	do {
		std::cout << " Enter your last name: ";
		std::getline(std::cin, arg);
	} while (arg.empty());
	myPhoneBook->contacts[currentRegistry].setLastName(arg);

	do {
		std::cout << " Enter your nickname: ";
		std::getline(std::cin, arg);
	} while (arg.empty());
	myPhoneBook->contacts[currentRegistry].setNickname(arg);

	do {
		std::cout << " Enter your phone number: ";
		std::getline(std::cin, arg);
	} while (arg.empty());
	myPhoneBook->contacts[currentRegistry].setPhoneNumber(arg);

	do {
		std::cout << " Enter your darkest secret: ";
		std::getline(std::cin, arg);
	} while (arg.empty());
	myPhoneBook->contacts[currentRegistry].setDarkestSecret(arg);
	(*registryNumber)++;
}

void	drawHeader()
{
	std::cout << "+------------+------------+------------+------------+" << std::endl;
	std::cout << "|   Index    | First Name | Last  Name |  Nickname  |" << std::endl;
	std::cout << "+------------+------------+------------+------------+" << std::endl;
}

int		countRecords(PhoneBook* myPhoneBook)
{
	int nbr = 0;
	for (int i = 0; i < 8; i++)
		if (!myPhoneBook->contacts[i].getFirstName().empty())
			nbr++;
	return (nbr);
}

int		countChars(PhoneBook* myPhoneBook, int i)
{
	int	size = 0;
	if (myPhoneBook->contacts[i].getFirstName().length() > size)
		size = myPhoneBook->contacts[i].getFirstName().length();
	if (myPhoneBook->contacts[i].getLastName().length() > size)
		size = myPhoneBook->contacts[i].getLastName().length();
	if (myPhoneBook->contacts[i].getNickname().length() > size)
		size = myPhoneBook->contacts[i].getNickname().length();
	if (myPhoneBook->contacts[i].getPhoneNumber().length() > size)
		size = myPhoneBook->contacts[i].getPhoneNumber().length();
	if (myPhoneBook->contacts[i].getDarkestSecret().length() > size)
		size = myPhoneBook->contacts[i].getDarkestSecret().length();
	return (size);
}

void	optionSearch(PhoneBook* myPhoneBook)
{
	std::string stringTmp;
	drawHeader();
	for (int i = 0; i < countRecords(myPhoneBook); i++)
	{
		std::cout << "| " << std::setw(10) << std::right << i + 1;
		stringTmp = myPhoneBook->contacts[i].getFirstName();
		if (myPhoneBook->contacts[i].getFirstName().length() > 10)
		{
			stringTmp.resize(9);
			stringTmp += ".";
		}
		std::cout << " | " << std::setw(10) << std::right << stringTmp;
		stringTmp = myPhoneBook->contacts[i].getLastName();
		if (myPhoneBook->contacts[i].getLastName().length() > 10)
		{
			stringTmp.resize(9);
			stringTmp += ".";
		}
		std::cout << " | " << std::setw(10) << std::right << stringTmp;
		stringTmp = myPhoneBook->contacts[i].getNickname();
		if (myPhoneBook->contacts[i].getNickname().length() > 10)
		{
			stringTmp.resize(9);
			stringTmp += ".";
		}
		std::cout << " | " << std::setw(10) << std::right << stringTmp;
		std::cout << " |" << std::endl;
	}
	std::cout << "+------------+------------+------------+------------+\n" << std::endl;
}

void	viewContact(PhoneBook* myPhoneBook, int index)
{
	std::string stringTmp;
	menu();
	int hyphen = countChars(myPhoneBook, index);
	std::cout << "+ ------------";
	for (int i = 0; i < hyphen; i++)
		std::cout << "-";
	std::cout << " + " << std::endl;
	std::cout << "| View Contact " << std::setw(16 + hyphen - 14) << std::right << " | " << std::endl;
	std::cout << "+ ------------";
	for (int i = 0; i < hyphen; i++)
		std::cout << "-";
	std::cout << " + " << std::endl;
	std::cout << "| Index: " << std::setw(16 + hyphen - 11) << std::left << index + 1 << " | " << std::endl;
	stringTmp = myPhoneBook->contacts[index].getFirstName();
	std::cout << "| First Name: " << std::setw(16 + hyphen - 16) << std::left << stringTmp << " | " << std::endl;
	stringTmp = myPhoneBook->contacts[index].getLastName();
	std::cout << "| Last Name: " << std::setw(16 + hyphen - 15) << std::left << stringTmp << " | " << std::endl;
	stringTmp = myPhoneBook->contacts[index].getNickname();
	std::cout << "| Nickname: " << std::setw(16 + hyphen - 14) << std::left << stringTmp << " | " << std::endl;
	std::cout << "+ ------------";
	for (int i = 0; i < hyphen; i++)
		std::cout << "-";
	std::cout << " + \n" << std::endl;
	std::string input;
	do {
		std::cout << "* Press ENTER to go back to SEARCH. ";
		std::getline(std::cin, input);
	} while (input.length() != 0);
}
