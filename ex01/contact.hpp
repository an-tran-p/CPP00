/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:13:31 by atran             #+#    #+#             */
/*   Updated: 2025/12/11 21:10:18 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

    static std::string truncate(const std::string &s, std::size_t width);

  public:
	Contact();
    static bool is_number(const std::string &s);
	bool set_contact();
	void display_list(int index) const;
	void display_contact() const;
};

#endif
