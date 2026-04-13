/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:59:44 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/04/13 18:51:59 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : cols(20), _idx(0), _max_idx(8) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::_RequestContact(PhoneBook& new_phonebook) {
	std::string message[5] = {FIRST_NAME, LAST_NAME, NICKNAME, PHONE_NUM, SECRET};
	std::string info[5];
	int	i = new_phonebook._idx;
	const int max = new_phonebook._max_idx;

	ft_set_format(new_phonebook);
	(std::cout << HIDE CLEAR, ft_center_rows(new_phonebook.rows / 3));
	ft_center_cols(new_phonebook.cols / 2 - 14);
	(std::cout << GREEN INSERT << std::endl, ft_sleep(2));
	for (int idx = 0; idx < 5; ++idx) {
		ft_set_format(new_phonebook);
		(std::cout << HIDE CLEAR, ft_center_rows(new_phonebook.rows / 3));
		(ft_center_cols(new_phonebook.cols / 2 - 14), std::cout << GREEN);
		std::cout << message[idx] << std::endl << std::endl << std::endl;
		(std::cout << SHOW, ft_center_cols(new_phonebook.cols / 2 - 14));
		std::cout << PROMPT;
		if (!std::getline(std::cin, info[idx])) {
			if (std::cin.eof()) {
				(std::cout << CLEAR, ft_center_rows(new_phonebook.rows / 3));
				ft_center_cols(new_phonebook.cols / 2 - 14);
				std::cout << HIDE GREEN TERM SHOW << std::endl;
				(new_phonebook.~PhoneBook(), std::exit(0));
			}
		}
		if (info[idx].empty()) {
			(std::cerr << std::endl << HIDE, ft_center_cols(new_phonebook.cols / 2 - 14));
			(std::cerr << EMPTY, ft_sleep(2));
			idx--;
		}
		std::cout << RESET;
	}
	new_phonebook._contacts[i].SaveContact(new_phonebook._contacts[i], info, 5);
	new_phonebook._idx += 1;
	if (new_phonebook._idx == max)
		new_phonebook._idx = 0;
}

void PhoneBook::_SearchContacts(PhoneBook& new_phonebook) {
	std::string field[3] = {"FIRST_NAME", "LAST_NAME", "NICKNAME"};
	int pos[2] = {new_phonebook.cols, new_phonebook.rows};
	std::string contact_id;

	while (1) {
		ft_set_format(new_phonebook);
		(std::cout << HIDE CLEAR, ft_center_rows(pos[1] / 3));
		ft_center_cols(pos[0] / 2 - 14);
		std::cout << GREEN LIST << std::endl << std::endl;
		(ft_center_cols(pos[0] / 2 - 14), std::cout << EDGE << std::setw(10) << ID);
		for (int i = 0; i < 3; ++i) {
			if (i == 0)
				std::cout << EDGE;
			std::cout << std::setw(10) << field[i] << EDGE;
		}
		std::cout << std::endl;
		for (int i = 0; i < new_phonebook._max_idx; ++i) {
			(ft_center_cols(pos[0] / 2 - 14), std::cout << EDGE << std::setw(10) <<  i);
			for (int j = 0; j < 3; ++j) {
				if (j == 0)
					std::cout << EDGE;
				std::cout << std::setw(10) << new_phonebook._contacts[i].search_format[j];
				std::cout << EDGE;
				if (j == 2)
					std::cout << std::endl;
			}
		}
		std::cout << std::endl << std::endl;
		(ft_center_cols(pos[0] / 2 - 14), std::cout << HIDE PICK << std::endl);
		(std::cout << std::endl, ft_center_cols(pos[0] / 2 - 14));
		std::cout << SHOW PROMPT;
		if (!std::getline(std::cin, contact_id)) {
			if (std::cin.eof()) {
				(std::cout << CLEAR, ft_center_rows(new_phonebook.rows / 3));
				ft_center_cols(new_phonebook.cols / 2 - 14);
				std::cout << HIDE GREEN TERM SHOW << std::endl;
				(new_phonebook.~PhoneBook(), std::exit(0));
			}
		}
		if (contact_id.empty()) {
			(std::cerr << std::endl, ft_center_cols(pos[0] / 2 - 14));
			(std::cerr << NO_INPUT, ft_sleep(2));
			continue ;
		}
		if (contact_id == "RETURN")
			return ;
		const char *new_id = contact_id.c_str();
		int id = std::atoi(new_id);
		int ret;
		if (!ft_valid_number(contact_id)) {
			std::cerr << HIDE << std::endl;
			ft_center_cols(pos[0] / 2 - 14);
			(std::cerr << GREEN NO_ID, ft_sleep(2));
			continue ;
		}
		if (id < 0 || id > 7) {
			std::cerr << HIDE << std::endl;
			ft_center_cols(pos[0] / 2 - 14);
			(std::cerr << GREEN ID_OUT, ft_sleep(2));
			continue ;
		}
		ret = new_phonebook._contacts[id].ShowContact(new_phonebook._contacts[id], new_phonebook);
		if (ret == -1)
			(new_phonebook.~PhoneBook(), std::cout << CLEAR RESET, std::exit(0));
		else if (ret == 1)
			return ;
	}
}

void PhoneBook::RequestAction(PhoneBook& new_phonebook) {
	std::string commands[3] = {"ADD", "SEARCH", "EXIT"};
	std::string input;

	while (1) {
		ft_set_format(new_phonebook);
		(std::cout << CLEAR HIDE, ft_center_rows(new_phonebook.rows / 3));
		(ft_center_cols(new_phonebook.cols / 2 - 14), std::cout << GREEN TAKE);
		for (int i = 0; i < 3; ++i) {
			std::cout << commands[i];
			if (i < 2)
				std::cout << COMMA;
		}
		std::cout << SHOW RESET << std::endl << std::endl;
		(ft_center_cols(new_phonebook.cols / 2 - 14), std::cout << GREEN CHOOSE);
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof()) {
				(std::cout << CLEAR, ft_center_rows(new_phonebook.rows / 3));
				ft_center_cols(new_phonebook.cols / 2 - 14);
				std::cout << HIDE GREEN TERM SHOW << std::endl;
				(new_phonebook.~PhoneBook(), std::exit(0));
			}
		}
		std::cout << RESET;
		if (input == commands[0]) {
			new_phonebook._RequestContact(new_phonebook);
		}
		else if (input == commands[1]) {
			new_phonebook._SearchContacts(new_phonebook);
		}
		else if (input == commands[2])
			(new_phonebook.~PhoneBook(), std::cout << CLEAR RESET, std::exit(0));
		else {
			std::cerr << HIDE << std::endl;
			ft_center_cols(new_phonebook.cols / 2 - 14);
			(std::cerr << GREEN NOT_FOUND, ft_sleep(2), std::cerr << SHOW RESET);
		}
	}
}