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
	if (idx >= 7)
		idx = 0;
	contacts[idx].assign_data();
	idx++;
	return ;
}

void	PhoneBook::desplay_all_contacts(void)
{
	int i;

	std::cout << std::right 
	<< std::setw(6) << "Index"
	<< std::setw(15) << "First Name"
	<< std::setw(15) << "Last Name"
	<< std::setw(15) << "Nickname" << std::endl;
	for(i = 0; i < idx ; i++)
	{
		std::cout << std::setw(6) << i << " |";
		contacts[i].desplay_phonebook_contacts();
		std::cout << "\n";
	}
	contacts_num = i - 1;
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
			if (i < 0 || i > contacts_num)
			{
				std::cout << "invalid index" << std::endl;
			}
			else
			{
				flag = true;
				break ;
			}
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
}

bool	contain_only_digits(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}


# endif