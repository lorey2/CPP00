/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:13:29 by lorey             #+#    #+#             */
/*   Updated: 2025/02/04 13:35:26 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE NOISE *";
	else
		for (int i = 1; i < argc; i++)
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char) toupper((unsigned char) argv[i][j]);
	std::cout << std::endl;
	return (0);
}
