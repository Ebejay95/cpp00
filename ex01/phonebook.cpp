/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:14:39 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/04 16:54:06 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"
#include "./PhoneBook.hpp"
#include "./main.hpp"

PhoneBook::PhoneBook() {

}

PhoneBook::~PhoneBook() {

}

bool is_only_whitespaces(const std::string& str)
{
	for (std::string::size_type i = 0; i < str.length(); ++i)
	{
		if (!std::isspace(static_cast<unsigned char>(str[i])))
		{
			return (false);
		}
	}
	std::cout << RED"Broo, add some content ...."D << std::endl;
	return (true);
}

bool nonnumerics(const std::string& str)
{
	for (std::string::size_type i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
		{
			std::cout << RED"Broo, phone number is numbers only ...."D << std::endl;
			return (true);
		}
	}
	return (false);
}

std::string trim(const std::string& str)
{
	std::string::size_type start = 0;
	while (start < str.length() && std::isspace(static_cast<unsigned char>(str[start]))) {
		++start;
	}
	std::string::size_type end = str.length();
	while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1]))) {
		--end;
	}
	return str.substr(start, end - start);
}

void PhoneBook::addContact()
{
	int i = 0;
	std::string first_name, last_name, nickname, phone_number, darkest_secret;

	while (first_name.empty() || is_only_whitespaces(first_name))
	{
		std::cout << C"😀> Enter First Name: "D;
		std::getline(std::cin, first_name);
		if (first_name.empty())
			std::cout << RED"Broo, add some content ...."D << std::endl;
	}
	while (last_name.empty() || is_only_whitespaces(last_name))
	{
		std::cout << C"😀> Enter Last Name: "D;
		std::getline(std::cin, last_name);
		if (last_name.empty())
			std::cout << RED"Broo, add some content ...."D << std::endl;
	}
	while (nickname.empty() || is_only_whitespaces(nickname))
	{
		std::cout << C"🤣> Enter Nickname: "D;
		std::getline(std::cin, nickname);
		if (nickname.empty())
			std::cout << RED"Broo, add some content ...."D << std::endl;
	}
	while (phone_number.empty() || is_only_whitespaces(phone_number)|| nonnumerics(phone_number))
	{
		std::cout << C"📱> Enter Phone Number TODO ADDD FUCKING SPACES SUPPORT: "D;
		std::getline(std::cin, phone_number);
		if (phone_number.empty())
			std::cout << RED"Broo, add some content ...."D << std::endl;
	}
	while (darkest_secret.empty() || is_only_whitespaces(darkest_secret))
	{
		std::cout << C"🤐> Enter Darkest Secret: "D;
		std::getline(std::cin, darkest_secret);
		if (darkest_secret.empty())
			std::cout << RED"Broo, add some content ...."D << std::endl;
	}

	while (i < CONTACT_MAX)
	{
		if (contacts[i].get_first_name().empty() || i == (CONTACT_MAX - 1))
		{
			first_name = trim(first_name);
			last_name = trim(last_name);
			nickname = trim(nickname);
			phone_number = trim(phone_number);
			darkest_secret = trim(darkest_secret);
			contacts[i].set_first_name(first_name);
			contacts[i].set_last_name(last_name);
			contacts[i].set_nickname(nickname);
			contacts[i].set_phone_number(phone_number);
			contacts[i].set_darkest_secret(darkest_secret);
			break;
		}
		i++;
	}
	std::cout << G"Contact added SUCESSFULLY: " << first_name << ", " << last_name << ", " << nickname << ", " << phone_number << ", " << darkest_secret << ", " << D << std::endl;
}


void PhoneBook::searchContacts()
{
	std::cout << C"this is SEARCH"D << std::endl;
}
