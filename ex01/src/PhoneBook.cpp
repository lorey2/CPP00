/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:13:29 by lorey             #+#    #+#             */
/*   Updated: 2025/04/24 15:39:01 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>
#include <ios>

PhoneBook::PhoneBook(void)
{
	nbr_contact = -1;
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::big_shift(void)
{
    for (int i = 0; i < 7; ++i)
		contact_array[i] = contact_array[i + 1];
}

void	PhoneBook::add_contact(void)
{
	nbr_contact++;
	if (nbr_contact >= 8)
	{
		nbr_contact = 7;
		big_shift();
	}
	contact_array[nbr_contact].set_name();
	contact_array[nbr_contact].set_l_name();
	contact_array[nbr_contact].set_n_name();
	contact_array[nbr_contact].set_number();
	contact_array[nbr_contact].set_secret();
}

std::string	format_name(std::string name)
{
	if (name.length() > 10)
		return (name.substr(0, 9) + ".");
	return (name);
}

void	write_contact(Contact contact)
{
	std::cout << "name: " << std::endl << contact.g_name() << std::endl;
	std::cout << "last name: " << std::endl << contact.g_l_name() << std::endl;
	std::cout << "nickname: " << std::endl << contact.g_n_name() << std::endl;
	std::cout << "number: " << std::endl << contact.g_number() << std::endl;
	std::cout << "darkest secret: " << std::endl << contact.g_secret() << std::endl;
}

void	get_entry(Contact *contact_array)
{
	std::string	entry;
	int			check;

	std::cout << "Wich entry interess you today [number]?" << std::endl;
	check = 0;
	while (entry.empty() || check == 1)
	{
		check = 0;
		std::getline(std::cin, entry);
		for (std::string::size_type i = 0; i < entry.size(); ++i)
		{
			if (!isdigit(entry[i]))
			{
				std::cout << "Index must be a number. Try again!" << std::endl;
				check = 1;
				break;
			}
		}
		if ((std::atoi(entry.c_str()) - 1 > 7 //check if entry less big than 7		c_str and then atoi is the easiest way to get a number I think
			|| std::atoi(entry.c_str()) - 1 < 0 //bigger than 0
			|| contact_array[std::atoi(entry.c_str()) - 1].g_number().empty()) //check if this entry has alreay been filled
			&& check == 0)
		{
			std::cout << "entry too big or negative or null" << std::endl;
			check = 1;
		}
		else if (check == 0)
			write_contact(contact_array[std::atoi(entry.c_str()) - 1]);
	}
}

void	PhoneBook::search(void)
{
	int	i;

	i = -1;
	while (!contact_array[++i].g_name().empty() && i < 8)
	{
		//setw makes that only 10 character can be displayed
		//format_name replace the 10th charac (if exists with a point)
		std::cout << std::setw(10) << std::right << i + 1 << "|";
		std::cout << std::setw(10) << std::right << format_name(contact_array[i].g_name()) << "|";
		std::cout << std::setw(10) << std::right << format_name(contact_array[i].g_l_name()) << "|";
		std::cout << std::setw(10) << std::right << format_name(contact_array[i].g_n_name());
		std::cout << std::endl;
	}
	if (i == 0)
		std::cout << "Phone book is empty :'(" << std::endl;
	else if (i == 1)
	{
		std::cout << "There is only one entry. Here is the details" << std::endl;
		write_contact(contact_array[0]);
	}
	else
		get_entry(contact_array);
}







