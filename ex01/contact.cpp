/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:13:44 by atran             #+#    #+#             */
/*   Updated: 2025/12/11 20:29:50 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <cctype>

Contact::Contact() : firstName(""), lastName(""), nickName(""), phoneNumber(""),
	darkestSecret("") {}

bool    Contact::is_number(const std::string &s) const
{
    for(size_t i = 0; i < s.length(); i++)
    {
        if (!std::isdigit(s[i]))
            return (false);
    }
}

std::string Contact::truncate(const std::string &s, std::size_t w)
{
    if (s.length() <= w)
        return (s);
    else if (s.length() > w)
        return s.substr(0, w - 1) + ".";
}

bool    Contact::set_contact()
{
    std::string input;

    std::cout << "First name: ";
    if (!std::getline(std::cin, input) || input.empty())
        return (false);
    firstName = input;

    std::cout << "Last name: ";
    if (!std::getline(std::cin, input) || input.empty())
        return (false);
    lastName = input;

    std::cout << "Nick name: ";
    if (!std::getline(std::cin, input) || input.empty())
        return (false);
    nickName = input;

    std::cout << "Phone number: ";
    if (!std::getline(std::cin, input) || input.empty() || !is_number(input))
        return (false);
    phoneNumber = input;

    std::cout << "Darkest secret: ";
    if (!std::getline(std::cin, input) || input.empty())
        return (false);
    darkestSecret = input;
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
