/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:14:18 by atran             #+#    #+#             */
/*   Updated: 2025/12/11 12:30:03 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook book;
	std::string input;

	while (true)
	{
		std::cout << "What would you want to do: ADD,
			SEARCH or EXIT?" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			book.addContact();
		else if (input == "SEARCH")
			book.searchContact();
		else if (input == "EXIT" || std::cin.eof())
			break ;
		else
			std::cout << "Please enter correct command: ADD,
				SEARCH or EXIT" << std::endl;
	}
}