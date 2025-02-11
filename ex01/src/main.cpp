/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:07:08 by lorey             #+#    #+#             */
/*   Updated: 2025/02/11 03:52:57 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	pb;
	std::string	prompt;

	while (true)
	{
		std::getline(std::cin, prompt);
		if (prompt == "EXIT")
			break;
		if (prompt == "ADD")
			pb.add_contact();
		if (prompt == "SEARCH")
			pb.search();
	}
}
