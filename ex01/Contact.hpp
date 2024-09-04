/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:35:01 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/04 14:20:13 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "./main.hpp"

class Contact
{
	private:
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		phone_number;
		std::string		darkest_secret;

	public:
		Contact();
		~Contact();

		void			set_first_name(const std::string& first_name);
		std::string		get_first_name() const;
		void			set_last_name(const std::string& last_name);
		std::string		get_last_name() const;
		void			set_nickname(const std::string& nickname);
		std::string		get_nickname() const;
		void			set_phone_number(const std::string& phone_number);
		std::string		get_phone_number() const;
		void			set_darkest_secret(const std::string& darkest_secret);
		std::string		get_darkest_secret() const;
};

#endif
