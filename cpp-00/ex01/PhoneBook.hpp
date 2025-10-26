#include <iostream>
#include <cstdlib>
#include <limits>
#include "Contact.hpp"

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


// macros 

# define RED "\033[1;31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"


// classes
class	PhoneBook
{
	private:
		Contact	contacts[8];
		int	idx;
	public :

		void	add_contact(void)
		{
				if (idx >= 8)
					idx = 0;
				contacts[idx].assign_data();
				idx++;
				return ;
		}

		void	search_for_contact(std::string name)
		{
			for(int i = 0 ; i < idx ; i++)
			{
				if (contacts[i].get_name() == name)
				{
					contacts[i].desplay_contact_infos(i, contacts);
					return ;
				}
			}
			std::cout << "Unexist UserName\n";
		}

		void	idx_init()
		{
			idx = 0;
		}

		void	get_all_arr()
		{
			for(int i = 0 ; i < 8 ; i++)
				contacts[i].desplay_contact_infos(i, contacts);
		}
		
		int	get_idx_value(void)
		{
			return (idx);
		}
};

# endif