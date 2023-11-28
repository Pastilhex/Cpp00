/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:06:13 by ialves-m          #+#    #+#             */
/*   Updated: 2023/11/28 11:32:16 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
	if (argc > 1)
		for (int i = 1; i < argc; i++)
		{
			std::string currentArg(argv[i]);
			for (int j = 0; j < currentArg.length(); j++)
				std::cout << (char)toupper(argv[i][j]);
		}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl; 
	return (0);
}
