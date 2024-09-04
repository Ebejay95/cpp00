/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:36:39 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/04 14:20:09 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "./main.hpp"
#include "./Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	getContact();
		void	searchContacts();
};


#endif
