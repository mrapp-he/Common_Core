/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:25:27 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/04/13 18:52:32 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void ft_sleep(long seconds) {
	std::time_t start = std::time(0);
	std::time_t current;
	
	while (1) {
		current = std::time(0);
		if (current - start >= seconds)
			return ;
	}
}

void ft_center_cols(int centerd_cols) {
	for (int i = 0; i < centerd_cols; ++i)
		std::cout << SPACE;
}

void ft_center_rows(int centerd_rows) {
	for (int i = 0; i < centerd_rows; ++i)
		std::cout << std::endl;
}

void ft_set_format(PhoneBook& new_phonebook) {
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &new_phonebook.window) > -1) {
		new_phonebook.cols = new_phonebook.window.ws_col;
		new_phonebook.rows = new_phonebook.window.ws_row;
	}
}

bool ft_valid_number(std::string number) {
	for (std::string::iterator i = number.begin(); i != number.end(); ++i) {
		if (*i < '0' || *i > '9')
			return (false);
	}
	return (true);
}
