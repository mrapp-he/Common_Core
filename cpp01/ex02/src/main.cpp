/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 12:04:43 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/04/13 12:13:26 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string* strPtr = &str;
	std::string& strRef = str;
	
	std::cout << &str << " " << strPtr << " " << &strRef << " " << str << " " << *strPtr << " " << strRef << std::endl;
	return (0);
}