/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:15:01 by ialves-m          #+#    #+#             */
/*   Updated: 2023/12/01 14:48:45 by ialves-m         ###   ########.fr       */
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
	std::cout << "  Enter your first name: ";
	std::getline(std::cin, arg);
	if (!arg.empty())
		myPhoneBook->contacts[currentRegistry].setFirstName(arg);
	else
		myPhoneBook->contacts[currentRegistry].emptyDetected = 1;
	std::cout << "  Enter your last name: ";
	std::getline(std::cin, arg);
	if (!arg.empty())
		myPhoneBook->contacts[currentRegistry].setLastName(arg);
	else
		myPhoneBook->contacts[currentRegistry].emptyDetected = 1;
	std::cout << "  Enter your nickname: ";
	std::getline(std::cin, arg);
	if (!arg.empty())
		myPhoneBook->contacts[currentRegistry].setNickname(arg);
	else
		myPhoneBook->contacts[currentRegistry].emptyDetected = 1;
	std::cout << "  Enter your phone number: ";
	std::getline(std::cin, arg);
	if (!arg.empty())
		myPhoneBook->contacts[currentRegistry].setPhoneNumber(arg);
	else
		myPhoneBook->contacts[currentRegistry].emptyDetected = 1;
	std::cout << "  Enter your darkest secret: ";
	std::getline(std::cin, arg);
	if (!arg.empty())
		myPhoneBook->contacts[currentRegistry].setDarkestSecret(arg);
	else
		myPhoneBook->contacts[currentRegistry].emptyDetected = 1;
	if (myPhoneBook->contacts[currentRegistry].emptyDetected == 0)
		(*registryNumber)++;
}

void	drawHeader(){
	std::cout << "+------------+------------+------------+------------+" << std::endl;
	std::cout << "|   Index    | First Name | Last  Name |  Nickname  |" << std::endl;
	std::cout << "+------------+------------+------------+------------+" << std::endl;
}

int		countRecords(PhoneBook* myPhoneBook){
	int nbr = 0;
	for (int i = 0; i < 8; i++)
		if (!myPhoneBook->contacts[i].getFirstName().empty())
			nbr++;
	return (nbr);
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
	std::cout << "+------------+------------+------------+------------+" << std::endl;
}

void	viewContact(PhoneBook* myPhoneBook, int index){
	std::string stringTmp;
	menu();
	drawHeader();
	std::cout << "| " << std::setw(10) << std::right << index + 1;
	stringTmp = myPhoneBook->contacts[index].getFirstName();
	if (myPhoneBook->contacts[index].getFirstName().length() > 10)
	{
		stringTmp.resize(9);
		stringTmp += ".";
	}
	std::cout << " | " << std::setw(10) << std::right << stringTmp;
	stringTmp = myPhoneBook->contacts[index].getLastName();
	if (myPhoneBook->contacts[index].getLastName().length() > 10)
	{
		stringTmp.resize(9);
		stringTmp += ".";
	}
	std::cout << " | " << std::setw(10) << std::right << stringTmp;
	stringTmp = myPhoneBook->contacts[index].getNickname();
	if (myPhoneBook->contacts[index].getNickname().length() > 10)
	{
		stringTmp.resize(9);
		stringTmp += ".";
	}
	std::cout << " | " << std::setw(10) << std::right << stringTmp;
	std::cout << " |" << std::endl;
	std::cout << "+------------+------------+------------+------------+" << std::endl;
	std::cout << " Press enter to continue." << std::endl;
	std::cin.get();
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
		if (myPhoneBook.contacts[currentRegistry].emptyDetected == 1){
			std::cout << " All fields required!" << std::endl;
			std::cout << " Choose option > ";
		}
		else
			std::cout << " Choose option > ";
		std::getline(std::cin, option);
		myPhoneBook.contacts[currentRegistry].emptyDetected = 0;
		if (option == "ADD"){
			optionAdd(arg, &myPhoneBook, currentRegistry, &registryNumber);
		}
		else if (option == "SEARCH"){
			std::string tmp = std::to_string(countRecords(&myPhoneBook));
			do {
				menu();
				optionSearch(&myPhoneBook);
				if (tmp > "0")
				{
					std::cout << "> Choose from index 1 to " << tmp << " to view Contact" << std::endl;
					std::cout << "> Press any other key to continue: ";	
				}
				else
					std::cout << "> Press any key to continue: ";	
				std::getline(std::cin, option);
				if (option >= "1" && option <= tmp)
					viewContact(&myPhoneBook, std::stoi(option) - 1);
			} while (option >= "1" && option <= tmp);
		}
	} while (option != "EXIT");
}
