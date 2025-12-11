/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:14:08 by atran             #+#    #+#             */
/*   Updated: 2025/12/11 21:41:12 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <sstream>

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
    int max_display;
    std::string input;
    int index;

    if (count == 0)
    {
        std::cout << "Phone book is empty" << std::endl;
        return;
    }
    std::cout << "|   Index|First Name| Last Name| Nick Name|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    if (count > 8)
        max_display = 8;
    else if (count <= 8)
        max_display = count;
    for (int i = 0; i < max_display; i++)
        contacts[i].display_list(i);

    std::cout << "Enter index of the contact you would like to view";
    if (!std::getline(std::cin, input))
    {
        std::cout <<"Input error or EOF" << std:: endl;
        return;
    }
    while (!Contact::is_number(input))
    {
        std::cout << "Index need to be a number" << std::endl;
        std::cout << "Enter index of the contact you would like to view";
        if (!std::getline(std::cin, input) || input.empty())
        {
            std::cout <<"Input error or EOF" << std:: endl;
            return;
        }
    }
    index = std::stoi(input);
    if (index < 0 || index >= max_display)
    {
        std::cout << "Index out of range" << std::endl;
        return;
    }
    contacts[index].display_contact();
}