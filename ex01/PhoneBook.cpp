/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:14:14 by mshershe          #+#    #+#             */
/*   Updated: 2026/01/24 22:47:47 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"



PhoneBook::PhoneBook()
{
	for (int i = 0; i < 8;i++)
		contacts_reg[i] = Contact();
	count = 0;
	next_index = 0;
}

void PhoneBook::add()
{
	std::string fst_name = "";
	std::string lst_name = "";
	std::string nick_name = "";
	std::string phone_num = "";
	std::string dark_secret = "";
	
	std::cout<< "Add you contact's info:"<<std::endl;
	std::cout<< "First Name: ";
	add_field(fst_name);
	std::cout<< "Last Name: ";
	add_field(lst_name);
	std::cout<< "Nickname: ";
	add_field(nick_name);
	std::cout<< "Phone Number: ";
	add_field(phone_num);
	while (!check_phonenum(phone_num))
	{
		std::cout<< "A phone number may have numbers or '+' in the beginning"<<std::endl;
		std::cout<< "Phone Number: ";
		add_field(phone_num);
	}
	std::cout<< "Darkest Secret: ";
	add_field(dark_secret);
	contacts_reg[next_index] = Contact(fst_name, lst_name, nick_name, phone_num, dark_secret);
	next_index++;
	if (next_index >= 8)
		next_index %= 8;
	if (count < 8)
		count++;
}

void PhoneBook::search()
{
	int n;

	if (count > 0)
		printbook();
	else
		std::cout<< "No contacts to display"<<std::endl;
	while (1 && count > 0)
	{
		std::cout<< "Enter the index number of the wanted contact: ";
		if (!(std::cin >> n))
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Please enter a number.\n";
			continue;
		}
		if (n > count || n < 1)
			std::cout<< "Enter a valid range"<<std::endl;
		else
			break;
	}
	if (count > 0 && n > 0)
		contacts_reg[n - 1].printcontact();
}

void PhoneBook::printbook()
{
	std::cout << std::right << std::setfill(' ');	
	std::cout << std::setw(10) << "Index" <<"|"
	<< std::setw(10) << "First Name"<<"|"
	<< std::setw(10) << "Last Name"<<"|"
	<< std::setw(10) << "Nickname" << std::endl;
	
	for (int i = 0; i < 43; i++)
	{
		if (i == 10 || i == 21 || i == 32)
			std::cout << "+";
		else
			std::cout << "-";
	}
	std::cout << std::endl;
	for (int i=0; i < count; i++)
	{
		std::cout << std::setw(10) << i+1;
		std::cout <<"|";
		printfield(contacts_reg[i].get_data("first_name"));
		std::cout <<"|";
		printfield(contacts_reg[i].get_data("last_name"));
		std::cout <<"|";
		printfield(contacts_reg[i].get_data("nickname"));
		std::cout << std::endl;
	}
}

void PhoneBook::printfield(std::string field)
{
	std::string s;

	s = field;
	if (field.length() > 10)
	{
		s = field.substr(0,9).append(".");
		std::cout<< std::setw(10)<< s;
	}
	else
		std::cout<< std::setw(10) << field;
}

bool PhoneBook::check_phonenum(std::string s)
{
	size_t i = 0;
	
	if (s.empty())
		return false;
		
	if (s[i] == '+' && i == 0)
		i++;
	for (; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}

void PhoneBook::add_field(std::string &s)
{
	while(1)
	{
		if (!(std::getline(std::cin >> std::ws, s)))
			exit(1);
		if (!s.empty())
			break;
		std::cout<< "Empty fields are not allowed"<<std::endl;
	}
}