/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:42:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/04/13 18:52:27 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int ac, char **av) {
	PhoneBook new_phonebook;
	
	(void)av;
	ft_set_format(new_phonebook);
	if (ac != 1) {
		(std::cerr << CLEAR HIDE, ft_center_rows(new_phonebook.rows / 3));
		ft_center_cols(new_phonebook.cols / 2 - 14); 
		return (std::cerr << GREEN ERR_ARG RESET, 1);
	}
	(std::cout << HIDE CLEAR, ft_center_rows(new_phonebook.rows / 3)); 
	ft_center_cols(new_phonebook.cols / 2 - 14);
	(std::cout << GREEN WLCM_MSG RESET << std::endl, ft_sleep(2));
	new_phonebook.RequestAction(new_phonebook);
	return (0);
}