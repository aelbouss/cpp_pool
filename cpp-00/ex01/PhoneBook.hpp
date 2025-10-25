#include <iostream>
#include "Contact.hpp"

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int	idx;
	public :

		void	add_contact(void)
		{
				if (idx >= 7)
					idx = 0;
				contacts[idx].assign_data();
				idx++;
				return ;
		}

		void	search_for_contact(std::string name)
		{
			for(int i = 0 ; i < 8 ; i++)
			{
				if (contacts[i].get_name() == name)
				{
					contacts[i].desplay_contact_infos(i);
					return ;
				}
			}
			std::cout << "Unexist UserName\n";
		}
		void	reset_idx()
		{
			idx = 0;
		}
		void	get_all_arr()
		{
			for(int i = 0 ; i < 8 ; i++)
				contacts[i].desplay_contact_infos(i);
		}
};

# endif