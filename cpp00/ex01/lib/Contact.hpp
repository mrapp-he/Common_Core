/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:32:54 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/04/13 18:48:06 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "PhoneBook.hpp"

//Forward declaration
class PhoneBook;

// _contact_info[0] = First name
// _contact_info[1] = Last name
// _contact_info[2] = Nickname
// _contact_info[3] = Phone number
// _contact_info[4] = Darkest secret

class Contact {
	public:
		Contact();
		~Contact();
		std::string search_format[5];
		int ShowContact(Contact show_contact, PhoneBook& new_phonebook);
		void SaveContact(Contact& phonebook_slot, std::string* info, int size);
	private:
		std::string _contact_info[5];
};

#endif