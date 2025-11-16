#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <limits>
#include <iomanip>
#include <string>
#include "Contact.hpp"

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


// macros 

# define RED "\033[1;31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"


void	eof_handling(void);
bool	contain_only_digits(std::string str);

// classes
class	PhoneBook
{
	private:
		Contact	contacts[8];
		int	idx;
		int	contacts_num;
	public :
		void	add_contact(void);
		void	search_for_contact(void);
		void	desplay_all_contacts(void);
		void	set_idx(void);
};

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

void	PhoneBook::desplay_all_contacts(void)
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

	desplay_all_contacts();
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


# endif