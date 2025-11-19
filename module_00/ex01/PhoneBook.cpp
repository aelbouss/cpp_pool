/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:39:14 by aelbouss          #+#    #+#             */
/*   Updated: 2025/11/19 23:39:15 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add_contact(void)
{
	if (idx >= 8)
		idx = 0;
	contacts[idx].assign_data();
	idx++;
	if (contacts_num <= 7)
		contacts_num++;
	return ;
}

void	PhoneBook::desplay_all_contact(void)
{
	int i;

	std::cout << "*-------------------------------------*" << std::endl;
	std::cout << std::right 
	<< std::setw(1) << "Index|"
	<< std::setw(2) << " First Name|"
	<< std::setw(2) << " Last Name|"
	<< std::setw(2) << " Nickname|" << std::endl;
	std::cout << "*-------------------------------------*" << std::endl;
	for(i = 0; i < contacts_num ; i++)
	{
		std::cout << std::setw(5) << i << "|";
		contacts[i].desplay_phonebook_contacts();
		std::cout << "*-------------------------------------*" << std::endl;
	}
}

void	PhoneBook::search_for_contact(void)
{
	std::string	option;
	int	i;
	int	flag;

	if (contacts_num == 0)
	{
		std::cout << BLUE <<"\nthe phonebook is empty try to add some contacts" << RESET << std::endl;
		return ;
	}
	desplay_all_contact();
	flag = false;
	do
	{
		std::cout << "enter the correct index : ";
		getline(std::cin, option);
		eof_handling();
		if (option.empty())
			std::cout << "the field cannot be empty" << std::endl;
		if (!contain_only_digits(option))
		{
			std::cout << "numeric input required " << std::endl;
			continue;
		}
		if (!option.empty() && contain_only_digits(option))
		{
			i = atoi((const char *)&option[0]);
			if (i < 0 || i > contacts_num - 1)
				std::cout << "invalid index" << std::endl;
			else
				{flag = true; break;}
		}
	} while (1);
	if (flag == true)
	{
		std::cout << "\n";
		contacts[i].get_contact_infos();
	}
}

void	PhoneBook::set_idx(void)
{
	idx = 0;
	contacts_num = 0;
}

bool	contain_only_digits(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (false);
		i++;
	}
	return (true);
}