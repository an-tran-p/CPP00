/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:14:08 by atran             #+#    #+#             */
/*   Updated: 2025/12/13 12:07:45 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

phoneBook::phoneBook() : count(0) {}

void    phoneBook::add_contact()
{
    int pos = count % 8;

    if (!contacts[pos].set_contact())
    {
        std::cout << "Contact not saved" << std::endl;
        return;
    }
    count++;
    std::cout << "Contact saved successfully" << std::endl;
}

void    phoneBook::search_contact() const
{
    int max_display = 0;
    std::string input;
    int index;

    if (count == 0)
    {
        std::cout << "Phone book is empty" << std::endl;
        return;
    }
    std::cout << "|" << std::setw(10) << "Index"
            << "|" << std::setw(10) << "First Name"
            << "|" << std::setw(10) << "Last Name"
            << "|" << std::setw(10) << "Nick Name"
            << "|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    if (count > 8)
        max_display = 8;
    else if (count <= 8)
        max_display = count;
    for (int i = 0; i < max_display; i++)
        contacts[i].display_list(i);

    std::cout << "Enter index of the contact you would like to view: ";
    while (true)
    {
        if (!std::getline(std::cin, input))
        {
            std::cout <<"Input error or EOF" << std:: endl;
            return;
        }
        if (!Contact::is_number(input))
        {
            std::cout << "Index need to be a number" << std::endl;
            std::cout << "Enter index of the contact you would like to view: ";
            continue;
        }
        index = std::stoi(input);
        if (index < 0 || index >= max_display)
        {
            std::cout << "Index out of range" << std::endl;
            return;
        }
        break;
    }
    contacts[index].display_contact();
}
