/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <loic.rey.vs@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:19:48 by lorey             #+#    #+#             */
/*   Updated: 2025/04/24 14:10:14 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
	private:
		std::string	name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	secret;

	public:
		Contact();
		~Contact();
		void 		set_name(void);
		void 		set_l_name(void);
		void 		set_n_name(void);
		void		set_number(void);
		void		set_secret(void);
		std::string	g_name(void);
		std::string	g_l_name(void);
		std::string	g_n_name(void);
		std::string	g_number(void);
		std::string	g_secret(void);

};

#endif
