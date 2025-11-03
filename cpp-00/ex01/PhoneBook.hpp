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
};

void	PhoneBook::add_contact(void)
{
	if (idx >= 8)
		idx = 0;
	contacts[idx].assign_data();
	idx++;
	return ;
}

void	search_for_contact(void)
{

}

# endif