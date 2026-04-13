/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:40:32 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/04/13 17:12:03 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>
#ifndef MSG
# define MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n"
#endif

std::string capitalize(std::string str){
	for (std::string::iterator i = str.begin(); i != str.end(); ++i)
		*i = std::toupper(static_cast<unsigned char>(*i));
	return (str);
}

int	main(int ac, char **av){
	if (ac == 1)
		return (std::cout << MSG, 1);
	for (int i = 1; i < ac; ++i) {
		std::cout << capitalize(std::string{*(av + i)});
		if (i + 1 < ac)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}