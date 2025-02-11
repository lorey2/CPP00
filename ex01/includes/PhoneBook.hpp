/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:28:27 by lorey             #+#    #+#             */
/*   Updated: 2025/02/11 03:50:50 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

# include <iostream>
# include <iomanip>
# include <string>

class PhoneBook
{
	private:
		int		nbr_contact;
		Contact contact_array[8];

	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact(void);
		void	big_shift(void);
		void	search(void);
};

#endif
