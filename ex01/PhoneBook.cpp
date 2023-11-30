/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:15:01 by ialves-m          #+#    #+#             */
/*   Updated: 2023/11/30 14:54:54 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void	menu(void)
{
	system("clear");
	std::cout << "   __        __        ___  __   __   __       " << std::endl;
	std::cout << "  |__) |__| /  \\ |\\ | |__  |__) /  \\ /  \\ |__/ " << std::endl;
	std::cout << "  |    |  | \\__/ | \\| |___ |__) \\__/ \\__/ |  \\ " << std::endl;
	std::cout << "                                               " << std::endl;
	std::cout << "     Choose one option: ADD - SEARCH - EXIT" << std::endl;
}

void	optionAdd(std::string arg, PhoneBook* myPhoneBook, int currentRegistry, int* registryNumber)
{
	std::cout << "Enter your first name:" << std::endl;
	std::getline(std::cin, arg);
	if (!arg.empty())
		myPhoneBook->contacts[currentRegistry].setFirstName(arg);
	else
		myPhoneBook->contacts[currentRegistry].emptyDetected = 1;
	std::cout << "Enter your last name:" << std::endl;
	std::getline(std::cin, arg);
	if (!arg.empty())
		myPhoneBook->contacts[currentRegistry].setLastName(arg);
	else
		myPhoneBook->contacts[currentRegistry].emptyDetected = 1;
	std::cout << "Enter your nickname:" << std::endl;
	std::getline(std::cin, arg);
	if (!arg.empty())
		myPhoneBook->contacts[currentRegistry].setNickname(arg);
	else
		myPhoneBook->contacts[currentRegistry].emptyDetected = 1;
	std::cout << "Enter your phone number:" << std::endl;
	std::getline(std::cin, arg);
	if (!arg.empty())
		myPhoneBook->contacts[currentRegistry].setPhoneNumber(arg);
	else
		myPhoneBook->contacts[currentRegistry].emptyDetected = 1;
	std::cout << "Enter your darkest secret:" << std::endl;
	std::getline(std::cin, arg);
	if (!arg.empty())
		myPhoneBook->contacts[currentRegistry].setDarkestSecret(arg);
	else
		myPhoneBook->contacts[currentRegistry].emptyDetected = 1;
	if (myPhoneBook->contacts[currentRegistry].emptyDetected == 0)
		(*registryNumber)++;
}

void	optionSearch(PhoneBook* myPhoneBook)
{
	std::string stringTmp;
	std::cout << "+------------+------------+------------+------------+" << std::endl;
	std::cout << "|   Index    | First Name | Last  Name |  Nickname  |" << std::endl;
	std::cout << "+------------+------------+------------+------------+" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "| " << std::setw(10) << std::right << i;
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
	std::cout << "+------------+------------+------------+------------+" << std::endl;
}

int main(void)
{
	std::string option;
	std::string arg;
	int	registryNumber = 0;
	PhoneBook myPhoneBook;

	do {
		int currentRegistry = registryNumber % 8;
		menu();
		std::cout << currentRegistry << std::endl;
		if (myPhoneBook.contacts[currentRegistry].emptyDetected != 1)
			std::getline(std::cin, option);
		myPhoneBook.contacts[currentRegistry].emptyDetected = 0;
		if (option == "ADD"){
			optionAdd(arg, &myPhoneBook, currentRegistry, &registryNumber);
		}
		else if (option == "SEARCH")
		{
			optionSearch(&myPhoneBook);
			std::getline(std::cin, option);
		}
		else if (option == "EXIT")
			std::cout << "Option EXIT" << std::endl;
	} while (option != "EXIT");
}
