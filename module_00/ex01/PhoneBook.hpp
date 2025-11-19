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

# endif