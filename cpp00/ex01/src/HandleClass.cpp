/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HandleClass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:27:45 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/11/04 12:30:02 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact() {}

Contact::~Contact() {}

PhoneBook::PhoneBook() : cols(20), _idx(0), _max_idx(8) {}

PhoneBook::~PhoneBook() {}
