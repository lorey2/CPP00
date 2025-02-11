/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:16:06 by lorey             #+#    #+#             */
/*   Updated: 2025/02/11 02:38:41 by lorey            ###   LAUSANNE.ch       */
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
	std::string name;

	while (name.empty())
	{
		std::cout << "Enter a name: ";
		std::getline(std::cin, name);
		if (name.empty())
			std::cout << "Name cannot be empty. Please enter a valid name" << std::endl;
	}
	this->name = name;
}

void	Contact::set_l_name()
{
	std::string l_name;

	while (l_name.empty())
	{
		std::cout << "Enter a last name: ";
		std::getline(std::cin, l_name);
		if (l_name.empty())
			std::cout << "Last name cannot be empty. Please enter a valid last name" << std::endl;
	}
	this->last_name = l_name;
}

void	Contact::set_n_name()
{
	std::string n_name;

	while (n_name.empty())
	{
		std::cout << "Enter a nickname: ";
		std::getline(std::cin, n_name);
		if (n_name.empty())
			std::cout << "Nickname cannot be empty. Please enter a valid nickname" << std::endl;
	}
	this->nickname = n_name;
}

void	Contact::set_number()
{
	std::string	number;
	int			check;

	check = 0;
	while (number.empty() 	|| check == 1)
	{
		check = 0;
		std::cout << "Enter a phone number: ";
		std::getline(std::cin, number);
		if (number.empty())
			std::cout << "Phone number cannot be empty. Please enter a valid phone number" << std::endl;
		for (std::string::size_type i = 0; i < number.size(); ++i)
		{
			if (!isdigit(number[i]))
			{
                std::cout << "Phone number must contain only digits. Try again!" << std::endl;
				check = 1;
				break;
			}
		}
	}
	this->phone_number = number;
}

void	Contact::set_secret()
{
	std::string	secret;

	while(secret.empty())
	{
		std::cout << "Enter your darkest secret: ";
		std::getline(std::cin, secret);
		if (secret.empty())
			std::cout << "No lie or nonsense there. You have to enter something" << std::endl;
	}
	this->secret = secret;
}

void	Contact::s_name(std::string name)
{
	this->name = name;
}

void	Contact::s_l_name(std::string l_name)
{
	this->last_name = l_name;
}

void	Contact::s_n_name(std::string n_name)
{
	this->nickname = n_name;
}

void	Contact::s_number(std::string number)
{
	this->phone_number = number;
}

void	Contact::s_secret(std::string secret)
{
	this->secret = secret;
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

