/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:13:57 by atran             #+#    #+#             */
/*   Updated: 2025/12/11 17:29:43 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class phoneBook
{
  private:
	Contact contacts[8];
	int count;

  public:
	phoneBook();
	void add_contact();
	void search_contact() const;
};

#endif