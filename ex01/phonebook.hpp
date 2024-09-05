/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:36:39 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/05 15:40:11 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "./main.hpp"
#include "./Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[CONTACT_MAX];
	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	getContact();
		void	searchContacts();
		bool	isFull() const;
};


#endif
