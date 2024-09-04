/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:21:23 by jeberle           #+#    #+#             */
/*   Updated: 2024/09/04 15:42:12 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"
#include "./main.hpp"

Contact::Contact() {

}

Contact::~Contact() {

}

void Contact::set_first_name(const std::string& first_name)
{
	this->first_name = first_name;
}

std::string	Contact::get_first_name() const
{
	return (this->first_name);
}

void	Contact::set_last_name(const std::string& last_name)
{
	this->last_name = last_name;
}

std::string	Contact::get_last_name() const
{
	return (this->last_name);
}

void	Contact::set_nickname(const std::string& nickname)
{
	this->nickname = nickname;
}

std::string	Contact::get_nickname() const
{
	return (this->nickname);
}

void	Contact::set_phone_number(const std::string& phone_number)
{
	this->phone_number = phone_number;
}

std::string	Contact::get_phone_number() const
{
	return (this->phone_number);
}

void	Contact::set_darkest_secret(const std::string& darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

std::string	Contact::get_darkest_secret() const
{
	return (this->darkest_secret);
}

