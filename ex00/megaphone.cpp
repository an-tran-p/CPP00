/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:33:05 by atran             #+#    #+#             */
/*   Updated: 2025/12/10 21:04:49 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

void	print_arg(char *arg)
{
	while (*arg)
	{
		std::cout << (char)std::toupper(*arg);
		arg++;
	}
}

int	main(int argc, char **argv)
{
	int i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < argc)
		{
			if (argv[i])
				print_arg(argv[i]);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}