/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:36:39 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/16 11:34:57 by jeberle          ###   ########.fr       */
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
		int		oldest_contact;
	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	getContact();
		void	searchContacts();
		bool	isFull() const;
		int		getFirstEmptyIndex() const;
};


#endif
