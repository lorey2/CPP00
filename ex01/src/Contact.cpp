/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:16:06 by lorey             #+#    #+#             */
/*   Updated: 2025/02/10 16:00:45 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cctype>

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

	while (number.empty() && check == 0)
	{
		check = 0;
		std::cout << "Enter a phone number: ";
		std::getline(std::cin, number);
		if (number.empty())
			std::cout << "Phone number cannot be empty. Please enter a valid phone number" << std::endl;
		for (char c : number)
		{
			if (!isdigit(c))
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
	char		ch;

	while(secret.empty())
	{
		std::cout << "Enter your darkest secret: ";
		std::cout << "\033[?25l";
		while ((ch = std::cin.get()) != '\n')
		{
			if (ch != '\n')
			{
				secret.push_back(ch);
				std::cout << "*";
			}
		}
		if (secret.empty())
			std::cout << "No lie or nonsense there. You have to enter something" << std::endl;
		std::cout << "\033[?25h";
	}
	this->secret = secret;
}
