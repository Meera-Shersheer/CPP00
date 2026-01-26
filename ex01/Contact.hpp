/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:12:43 by mshershe          #+#    #+#             */
/*   Updated: 2026/01/24 22:28:21 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iomanip>
#include <iostream>

class Contact
{
	public:
		private:
			std::string first_name;
			std::string last_name;
			std::string nickname;
			std::string phone_number;
			std::string darkest_secret;

			
			public:
			Contact();
			Contact(std::string fst_name, std::string lst_name, std::string nick_name, std::string phonenum, std::string dark_secret);
			void printcontact();
			std::string get_data(std::string field);

};

#endif