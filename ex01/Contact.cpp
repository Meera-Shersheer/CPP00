/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:14:34 by mshershe          #+#    #+#             */
/*   Updated: 2026/01/20 14:14:41 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}

Contact::Contact(std::string fst_name, std::string lst_name, std::string nick_name, std::string phonenum, std::string dark_secret)
{
	first_name = fst_name;
	last_name = lst_name;
	nickname = nick_name;
	phone_number = phonenum;
	darkest_secret = dark_secret;
}

void Contact::printcontact()
{
	std::cout << "First Name: " <<first_name << std::endl;
	std::cout << "Last Name: " <<last_name << std::endl;
	std::cout <<"Nickname: " << nickname << std::endl;
	std::cout <<"Phone Number: " << phone_number << std::endl;
	std::cout <<"Darkest Secret: " << darkest_secret << std::endl;
}

std::string Contact::get_data(std::string field)
{
	if (field == "first_name")
		return first_name;
	else if (field == "last_name")
		return last_name;
	else if (field == "nickname")
		return nickname;
	else 
		return "";
}
