/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:01:24 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/11/04 17:58:13 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::SaveContact(Contact& phonebook_slot, std::string* info, int size) {
	for (int i = 0; i < size; ++i) {
		phonebook_slot._contact_info[i].assign(info[i]);
		size_t len = info[i].length();
		if (len > 10) {
			info[i].erase(9, len - 10);
			info[i].at(9) = DOT;
		}
		phonebook_slot.search_format[i].assign(info[i]);
	}
}

int Contact::ShowContact(Contact show_contact, PhoneBook& new_phonebook) {
	std::string fields[5] = {SHOW_FIRST, SHOW_LAST, SHOW_NICK, SHOW_NUM, SHOW_SECRET};
	int pos[2] = {new_phonebook.cols, new_phonebook.rows};
	std::string cmds[3] = {"RETRY", "RETURN", "EXIT"};
	std::string input;

	ft_set_format(new_phonebook);
	if (show_contact._contact_info[0].empty()) {
		(std::cerr << std::endl, ft_center_cols(pos[0] / 2 - 14));
		std::cerr << HIDE GREEN NO_CONTACT;
		return (ft_sleep(2), std::cerr << SHOW RESET, 0);
	}
	while (1) {
		ft_set_format(new_phonebook);
		(std::cout << CLEAR, ft_center_rows(pos[1] / 3));
		for (int i = 0; i < 5; ++i) {
			ft_set_format(new_phonebook);
			(ft_center_cols(pos[0] / 2 - 14), std::cout << GREEN << fields[i]);
			std::cout << show_contact._contact_info[i] << std::endl;
		}
		ft_set_format(new_phonebook);
		(std::cout << std::endl, ft_center_cols(pos[0] / 2 - 14));
		std::cout << GREEN TAKE << cmds[0] << SPACE << cmds[1];
		(std::cout << SPACE << cmds[2] << std::endl, ft_center_cols(pos[0] / 2 - 14));
		std::cout << GREEN CHOOSE;
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof()) {
				(std::cout << CLEAR, ft_center_rows(pos[1] / 3));
				ft_center_cols(pos[0] / 2 - 14);
				std::cout << HIDE GREEN TERM SHOW << std::endl;
				(new_phonebook.~PhoneBook(), std::exit(0));
			}
		}
		if (input == cmds[0])
			return (0);
		else if (input == cmds[1])
			return (1);
		else if (input == cmds[2])
			return (-1);
		else {
			(ft_center_cols(pos[0] / 2 - 14), std::cerr << std::endl);
			(std::cerr << HIDE GREEN NOT_FOUND, ft_sleep(2), std::cerr << SHOW RESET);
		}
	}
}
