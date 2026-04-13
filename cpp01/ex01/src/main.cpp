/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:21:38 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/04/11 10:58:15 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie* horde = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; ++i)
		horde[i].announce();
	delete[] horde;
	return (0);
}