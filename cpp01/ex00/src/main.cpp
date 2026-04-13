/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:21:38 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/04/10 11:02:51 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie* zombies[5];
	std::string chumps[3] = {"Chump1", "Chump2", "Chump3"};
	std::string names[5] = {"Zombie1", "Zombie2", "Zombie3", "Zombie4", "Zombie5"};
	int j = 0;

	for (int i = 0; i < 5; ++i) {
		if (i % 2 == 0)
			randomChump(chumps[j++]);
		zombies[i] = newZombie(names[i]);
		zombies[i]->announce();
	}
	for (int i  = 0; i < 5; ++i)
		delete (zombies[i]);
	return (0);
}