/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:14:39 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/16 12:00:51 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"
#include "./PhoneBook.hpp"
#include "./main.hpp"


PhoneBook::PhoneBook() : oldest_contact(0) {
}

PhoneBook::~PhoneBook() {
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

bool is_valid_input(const std::string& str, bool is_phone, bool is_secret, bool is_name)
{
	std::string trimmed = trim(str);
	if (trimmed.length() < 2)
	{
		std::cout << RED"Input must contain at least 2 non-whitespace characters." D << std::endl;
		return false;
	}
	if (!is_secret && trimmed.length() > 20)
	{
		std::cout << RED"Input must not exceed 20 characters." D << std::endl;
		return false;
	}
	if (is_name)
	{
		for (std::string::const_iterator it = trimmed.begin(); it != trimmed.end(); ++it)
		{
			if (std::isdigit(*it))
			{
				std::cout << RED"Names cannot contain digits." D << std::endl;
				return false;
			}
		}
	}
	if (is_phone)
	{
		bool has_digit = false;
		for (std::string::const_iterator it = trimmed.begin(); it != trimmed.end(); ++it)
		{
			if (std::isdigit(*it))
			{
				has_digit = true;
				break;
			}
		}
		if (!has_digit)
		{
			std::cout << RED"Phone number must contain at least one digit." D << std::endl;
			return false;
		}
	}
	return true;
}

bool is_valid_phone_number(const std::string& str)
{
	std::string trimmed = trim(str);
	bool lastCharWasSpace = false;
	bool hasContent = false;

	for (std::string::const_iterator it = trimmed.begin(); it != trimmed.end(); ++it)
	{
		if (std::isdigit(*it))
		{
			hasContent = true;
			lastCharWasSpace = false;
		}
		else if (*it == ' ')
		{
			if (lastCharWasSpace && hasContent)
			{
				std::cout << RED"No consecutive spaces allowed in the middle of the phone number." D << std::endl;
				return false;
			}
			lastCharWasSpace = true;
		}
		else
		{
			std::cout << RED"Phone number can only contain digits and spaces." D << std::endl;
			return false;
		}
	}

	return is_valid_input(trimmed, true, false, false);
}

std::string formatColumn(const std::string& text, int width)
{
	size_t width_size_t = static_cast<size_t>(width);

	if (text.length() > width_size_t) {
		return text.substr(0, width_size_t - 1) + ".";
	} else {
		return std::string(width_size_t - text.length(), ' ') + text;
	}
}

std::string intToString(int number) {
	std::ostringstream oss;
	oss << number;
	return oss.str();
}

bool PhoneBook::isFull() const {
	return !contacts[CONTACT_MAX - 1].get_first_name().empty();
}

void PhoneBook::addContact()
{
	const char* user = std::getenv("USER");
	if (!user)
		user = "User";
	std::string first_name, last_name, nickname, phone_number, darkest_secret;

	do {
		std::cout << C"😀> Enter First Name: " D;
		if (!std::getline(std::cin, first_name))
		{
			std::cout << RED"\nError: End of file encountered. Exiting program." D << std::endl;
			std::cout << C"Contacts are flushed... " D << std::endl;
			std::cout << C"<< 📞📖 Goodbye " D << B << user << D << C"! 📞📖 >>" D << std::endl;
			exit(1);
		}
	} while (!is_valid_input(first_name, false, false, true));

	do {
		std::cout << C"😀> Enter Last Name: " D;
		if (!std::getline(std::cin, last_name))
		{
			std::cout << RED"\nError: End of file encountered. Exiting program." D << std::endl;
			std::cout << C"Contacts are flushed... " D << std::endl;
			std::cout << C"<< 📞📖 Goodbye " D << B << user << D << C"! 📞📖 >>" D << std::endl;
			exit(1);
		}
	} while (!is_valid_input(last_name, false, false, true));

	do {
		std::cout << C"🤣> Enter Nickname: " D;
		if (!std::getline(std::cin, nickname))
		{
			std::cout << RED"\nError: End of file encountered. Exiting program." D << std::endl;
			std::cout << C"Contacts are flushed... " D << std::endl;
			std::cout << C"<< 📞📖 Goodbye " D << B << user << D << C"! 📞📖 >>" D << std::endl;
			exit(1);
		}
	} while (!is_valid_input(nickname, false, false, false));

	do {
		std::cout << C"📱> Enter Phone Number: " D;
		if (!std::getline(std::cin, phone_number))
		{
			std::cout << RED"\nError: End of file encountered. Exiting program." D << std::endl;
			std::cout << C"Contacts are flushed... " D << std::endl;
			std::cout << C"<< 📞📖 Goodbye " D << B << user << D << C"! 📞📖 >>" D << std::endl;
			exit(1);
		}
	} while (!is_valid_phone_number(phone_number));

	do {
		std::cout << C"🤐> Enter Darkest Secret: " D;
		if (!std::getline(std::cin, darkest_secret))
		{
			std::cout << RED"\nError: End of file encountered. Exiting program." D << std::endl;
			std::cout << C"Contacts are flushed... " D << std::endl;
			std::cout << C"<< 📞📖 Goodbye " D << B << user << D << C"! 📞📖 >>" D << std::endl;
			exit(1);
		}
	} while (!is_valid_input(darkest_secret, false, true, false));

	int index = oldest_contact;
	contacts[index].set_first_name(trim(first_name));
	contacts[index].set_last_name(trim(last_name));
	contacts[index].set_nickname(trim(nickname));
	contacts[index].set_phone_number(trim(phone_number));
	contacts[index].set_darkest_secret(trim(darkest_secret));

	oldest_contact = (oldest_contact + 1) % CONTACT_MAX;

	std::cout << G"Contact added SUCCESSFULLY: " << trim(first_name) << ", " << trim(last_name) << ", " << trim(nickname) << ", " << trim(phone_number) << ", " << trim(darkest_secret) << "!" << D << std::endl;
}

void PhoneBook::searchContacts()
{
	const char* user = std::getenv("USER");
	if (!user)
		user = "User";
	std::string first_name, last_name, nickname;
	const int width = 10;
	std::string line = "╠══════════╬══════════╬══════════╬══════════╣";

	while (true) {
		std::cout << M << "╔══════════╦══════════╦══════════╦══════════╗" << D << std::endl;
		std::cout << M << "║"
				  << Y << formatColumn("Index", width) << M << "║"
				  << D << formatColumn("First Name", width) << M << "║"
				  << D << formatColumn("Last Name", width) << M << "║"
				  << D << formatColumn("Nickname", width) << M << "║"
				  << D << std::endl;
		std::cout << M << line << D << std::endl;

		for (int i = 0; i < CONTACT_MAX; ++i)
		{
			if (!contacts[i].get_first_name().empty())
			{
				first_name = formatColumn(contacts[i].get_first_name(), width);
				last_name = formatColumn(contacts[i].get_last_name(), width);
				nickname = formatColumn(contacts[i].get_nickname(), width);

				std::cout << M << "║"
						  << Y << formatColumn(intToString(i + 1), width) << D << M << "|"
						  << D << first_name << M << "|"
						  << D << last_name << M << "|"
						  << D << nickname << M << "║"
						  << D << std::endl;
			}
		}

		std::cout << M << "╚══════════╩══════════╩══════════╩══════════╝" << D << std::endl;

		int index;
		while (true) {
			std::cout << M << "Enter an index to show its details or type 'EXIT' for main prompt: " << D;
			std::string input;
			if (!std::getline(std::cin, input))
			{
				std::cout << RED"\nError: End of file encountered. Exiting program." D << std::endl;
				std::cout << C"Contacts are flushed... " D << std::endl;
				std::cout << C"<< 📞📖 Goodbye " D << B << user << D << C"! 📞📖 >>" D << std::endl;
				exit(1);
			}

			if (input == "EXIT") {
				return;
			}

			if (input.empty()) {
				std::cout << RED << "Input cannot be empty. Please enter a valid index or type 'EXIT'." << D << std::endl;
				continue;
			}

			std::istringstream iss(input);
			if (!(iss >> index) || !iss.eof()) {
				std::cout << RED << "Invalid input. Please enter a valid index or type 'EXIT'." << D << std::endl;
				continue;
			}

			if (index < 1 || index > CONTACT_MAX || contacts[index - 1].get_first_name().empty()) {
				std::cout << RED << "Invalid Index. Please enter a valid index or type 'EXIT'." << D << std::endl;
			} else {
				std::cout << M << "═-" << D << std::endl;
				std::cout << "First Name: " << contacts[index - 1].get_first_name() << std::endl;
				std::cout << "Last Name: " << contacts[index - 1].get_last_name() << std::endl;
				std::cout << "Nickname: " << contacts[index - 1].get_nickname() << std::endl;
				std::cout << "Phone Number: " << contacts[index - 1].get_phone_number() << std::endl;
				std::cout << "Darkest Secret: " << contacts[index - 1].get_darkest_secret() << std::endl;
				std::cout << M << "═-" << D << std::endl;
				break;
			}
		}
	}
}
