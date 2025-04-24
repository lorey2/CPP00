/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:16:06 by lorey             #+#    #+#             */
/*   Updated: 2025/04/24 14:30:00 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cctype>
#include <string>

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::set_name()
{
	do {
		std::cout << "Enter a name: ";
		std::getline(std::cin, name);
		if (name.empty())
			std::cout << "Name cannot be empty. Please enter a valid name" << std::endl;
	} while (name.empty());
}

void	Contact::set_l_name()
{
	do {
		std::cout << "Enter a last name: ";
		std::getline(std::cin, last_name);
		if (last_name.empty())
			std::cout << "Last name cannot be empty. Please enter a valid last name" << std::endl;
	} while (last_name.empty());
}

void	Contact::set_n_name()
{
	
	do {
		std::cout << "Enter a nickname: ";
		std::getline(std::cin, nickname);
		if (nickname.empty())
			std::cout << "Nickname cannot be empty. Please enter a valid nickname" << std::endl;
	} while (nickname.empty());
}

void	Contact::set_number()
{
	int			check;

	do {
		check = 0;
		std::cout << "Enter a phone number: ";
		std::getline(std::cin, phone_number);
		if (phone_number.empty())
			std::cout << "Phone number cannot be empty. Please enter a valid phone number" << std::endl;
		for (std::string::size_type i = 0; i < phone_number.size(); ++i)
		{
			if (!isdigit(phone_number[i]))
			{
                std::cout << "Phone number must contain only digits. Try again!" << std::endl;
				check = 1;
				break;
			}
		}
	} while (phone_number.empty() || check == 1);
}

void	Contact::set_secret()
{
	do {
		std::cout << "Enter your darkest secret: ";
		std::getline(std::cin, secret);
		if (secret.empty())
			std::cout << "No lie or nonsense there. You have to enter something" << std::endl;
	} while(secret.empty());
}

std::string	Contact::g_name()
{
	return (name);
}

std::string	Contact::g_l_name()
{
	return (last_name);
}

std::string	Contact::g_n_name()
{
	return (nickname);
}

std::string	Contact::g_number()
{
	return (phone_number);
}

std::string	Contact::g_secret()
{
	return (secret);
}

