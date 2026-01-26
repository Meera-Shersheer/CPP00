/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:18:16 by mshershe          #+#    #+#             */
/*   Updated: 2026/01/20 14:18:21 by mshershe         ###   ########.fr       */
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
		if (!(std::getline(std::cin >> std::ws, choice)))
			exit(1);
		if (choice == "ADD")
			phone_reg.add();
		else if (choice == "SEARCH")
			phone_reg.search();
		else if (choice == "EXIT")
		{
			
            std::cout << "See you later!" << std::endl;
			break;
		}
	}
	return 0;
}
