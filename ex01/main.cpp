/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:18:16 by mshershe          #+#    #+#             */
/*   Updated: 2026/01/28 17:40:37 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string choice;
	PhoneBook phone_reg;

	phone_reg = PhoneBook();
	std::cout << "Your using the phonebook."<< std::endl;
	while (1)
	{
		std::cout << "What you want to do: ADD, SEARCH, or EXIT"<< std::endl;
		std::cout << "> ";
		if (!(std::getline(std::cin >> std::ws, choice)))
			return (1);
		if (choice == "ADD")
			phone_reg.add();
		else if (choice == "SEARCH")
			phone_reg.search();
		else if (choice == "EXIT")
		{
			
            std::cout << "See you later!" << std::endl;
			break;
		}
		else
			std::cout << "OOPs, you can only chose one of the following commands: ADD, SEARCH, or EXIT"<< std::endl;
	}
	return 0;
}
