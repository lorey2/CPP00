/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:13:29 by lorey             #+#    #+#             */
/*   Updated: 2025/02/10 15:10:52 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->nbr_contact = -1;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add_contact(void)
{
	this->nbr_contact++;
	this->contact_array[this->nbr_contact].set_name();
	this->contact_array[this->nbr_contact].set_l_name();
	this->contact_array[this->nbr_contact].set_n_name();
	this->contact_array[this->nbr_contact].set_number();
	this->contact_array[this->nbr_contact].set_secret();
}
