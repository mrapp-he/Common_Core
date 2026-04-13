/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 10:50:13 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/04/11 11:04:08 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name) {
	if (n <= 0)
		return (NULL);
	Zombie* horde = new Zombie[n];
	for (int i = 0; i < n; ++i) {
		std::ostringstream id;
		(id << i, horde[i].zombieName(name + id.str()));
	}
	return (horde);
}