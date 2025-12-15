/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:14:18 by atran             #+#    #+#             */
/*   Updated: 2025/12/15 15:26:55 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

int	main(void)
{
	phoneBook book;
	std::string input;

	while (true)
	{
		std::cout << "What would you want to do: ADD, SEARCH or EXIT? ";
		if (!std::getline(std::cin, input))
            break;
		if (input == "ADD")
			book.add_contact();
		else if (input == "SEARCH")
			book.search_contact();
		else if (input == "EXIT" || std::cin.eof())
			break ;
		else
			std::cout << "Invalid command" << std::endl;
	}
    return (0);
}