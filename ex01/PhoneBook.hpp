/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:13:42 by mshershe          #+#    #+#             */
/*   Updated: 2026/01/24 22:28:28 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <cstdlib>

class PhoneBook
{
	private:
		Contact contacts_reg[8];
		int count;
		int next_index;
	
		void printfield(std::string field);
		void printbook();
		bool check_phonenum(std::string s);
		void add_field(std::string &s);

	public:
		PhoneBook();
		void add();
		void search();

};
#endif