/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:36:15 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/11/04 18:06:42 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <ctime>
# include <string>
# include <limits>
# include <cstdio>
# include <iomanip>
# include <cstdlib>
# include <iostream>
# include <unistd.h>
# include <sys/ioctl.h>
# include "Defines.hpp"
# include "Contact.hpp"


class PhoneBook {
	public:
		int cols;
		int rows;
		PhoneBook();
		~PhoneBook();
		winsize window;
		void RequestAction(PhoneBook& new_phonebook);
	private:
		int _idx;
		const int _max_idx;
		Contact _contacts[8];
		void _SearchContacts(PhoneBook& new_phonebook);
		void _RequestContact(PhoneBook& new_phonebook);
};

void ft_sleep(long seconds);
void ft_center_cols(int centerd_cols);
void ft_center_rows(int centerd_rows);
bool ft_valid_number(std::string number);
void ft_set_format(PhoneBook& new_phonebook);

#endif