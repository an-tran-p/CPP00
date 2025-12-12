/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:13:44 by atran             #+#    #+#             */
/*   Updated: 2025/12/12 16:23:05 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <cctype>

Contact::Contact() : firstName(""), lastName(""), nickName(""), phoneNumber(""),
	darkestSecret("") {}

bool    Contact::is_number(const std::string &s)
{
    for(size_t i = 0; i < s.length(); i++)
    {
        if (!std::isdigit(s[i]))
            return (false);
    }
    return (true);
}

std::string Contact::truncate(const std::string &s, std::size_t w)
{
    if (s.length() <= w)
        return (s);
    else
        return s.substr(0, w - 1) + ".";
}

std::string prompt_input(std::string field)
{
    std::string input;

    while (true)
    {
        std::cout << field;
        if (!std::getline(std::cin, input))
            return "";
        else if (input.empty())
        {
            std::cout << "Field can't be empty: " << std::endl;
            continue;
        }
        return (input);
    }
}

bool    Contact::set_contact()
{
    std::string input;

    input = prompt_input("First name: ");
    if (input.empty())
        return (false);
    firstName = input;

    input = prompt_input("Last name: ");
    if (input.empty())
        return (false);
    lastName = input;

    input = prompt_input("Nick name: ");
    if (input.empty())
        return (false);
    nickName = input;

    input = prompt_input("Phone number: ");
    if (input.empty())
        return (false);
    while (!is_number(input))
    {
        std::cout << "Phone number can only contains digits" << std::endl;
         input = prompt_input("Phone number: ");
        if (input.empty())
            return (false);
    }
    phoneNumber = input;

    input = prompt_input("Darkest secret: ");
    if (input.empty())
        return (false);
    darkestSecret = input;
    return (true);
}

void    Contact::display_list(int index) const
{
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << truncate(firstName, 10);
    std::cout << "|" << std::setw(10) << truncate(lastName, 10);
    std::cout << "|" << std::setw(10) << truncate(nickName, 10);
    std::cout << "|" << std::endl;
}

void    Contact::display_contact() const
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nick name: " << nickName << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
