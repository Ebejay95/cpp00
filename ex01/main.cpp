/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 23:02:31 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/05 15:51:12 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.hpp"
#include "./PhoneBook.hpp"


int main(void)
{
    PhoneBook phonebook;
    std::string command;
    const char* user = std::getenv("USER");
    if (!user)
        user = "User";
    std::cout << C "<< 📞📖 Hello " D << B << user << D << C ", Welcome to your Phone Book! 📞📖 >>" D << std::endl;
 
    while (1)
    {
        if (phonebook.isFull())
        {
			std::cout << C "Enter a command (" D << G"ADD (overwrites last contact)" D << C", " D << Y"SEARCH" D << C", " D << RED"EXIT" D << D"): " D;
        }
		else
		{
			std::cout << C "Enter a command (" D << G"ADD" D << C", " D << Y"SEARCH" D << C", " D << RED"EXIT" D << D"): " D;
		}
        std::getline(std::cin, command);
        if (command == "ADD")
        {
            phonebook.addContact();
        }
        else if (command == "SEARCH")
            phonebook.searchContacts();
        else if (command == "EXIT")
        {
            std::cout << C"Contacts are flushed... " D << std::endl;
            std::cout << C"<< 📞📖 Goodbye " D << B << user << D << C"! 📞📖 >>" D << std::endl;
            return (0);
        }
    }
    return (0);
}
