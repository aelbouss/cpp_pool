#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include "Contact.hpp"

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


// macros 

# define RED "\033[1;31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"


void	eof_handling(void);

// classes
class	PhoneBook
{
	private:
		Contact	contacts[8];
		int	idx;
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
	std::cout << std::right 
	<< std::setw(5) << "Index"
	<< std::setw(18) << "First Name"
	<< std::setw(18) << "Last Name"
	<< std::setw(18) << "Nickname" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	for(int i = 0; i < idx ; i++)
	{
		std::cout << std::setw(5) << i << std::setw(5) << " |";
		contacts[i].desplay_phonebook_contacts();
		std::cout << "------------------------------------------------------------" << std::endl;
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
		std::cout << "enter the  index of the  contact you want : ";
		getline(std::cin, option);
		eof_handling();
		if (option.empty())
			std::cout << "the file cannot be empty" << std::endl;
		if (!option.empty())
		{
			i = atoi((const char *)&option);
			if (i < 0 || i > (idx - 1))
			{
				std::cout << "incorrect index" << std::endl;
			}
			else
			{
				flag = true;
				break ;
			}
		}
	} while (1);
	if (flag == true)
		contacts[i].get_contact_infos();
}

void	PhoneBook::set_idx(void)
{
	idx = 0;
}



# endif