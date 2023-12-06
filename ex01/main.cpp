/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:26:33 by ialves-m          #+#    #+#             */
/*   Updated: 2023/12/06 14:26:01 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	std::string option;
	std::string arg;
	int	registryNumber = 0;
	PhoneBook myPhoneBook;
	do {
		int currentRegistry = registryNumber % 8;
		menu();
		std::cout << "* Choose option > ";
		std::getline(std::cin, option);
		if (std::cin.eof())
			break;
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
					std::cout << "* Choose from index 1 to " << tmp << " to view Contact." << std::endl;
					std::cout << "* Choose 0 to go back to MENU. ";
				}
				else
					std::cout << "* No records to display. Choose 0 to go back to MENU. ";	
				std::getline(std::cin, option);
				if (std::cin.eof())
					exit(130);
				if (option >= "1" && option <= tmp)
					viewContact(&myPhoneBook, std::stoi(option) - 1);
			} while ((option >= "1" && option <= tmp) || option != "0");
		}
	} while (option != "EXIT");
}
