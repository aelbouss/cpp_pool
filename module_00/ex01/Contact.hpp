#include <iostream>
#include <limits>
#include <iomanip>
#include <ctype.h>
#include <cstdlib>


# ifndef CONTACT_HPP
# define CONTACT_HPP

// macros

# define RED "\033[1;31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define BLUE "\33[34m"

void	eof_handling(void);
void	put_str_8_chars(std::string s);
int	validate_phonenumber(std::string str);

class	Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string	nickname;
		std::string phone_number;
		std::string	darkest_secret;
	public:

		void	take_first_name(void);
		void	take_last_name(void);
		void	take_nick_name(void);
		void	take_phone_number(void);
		void	take_darkest_secret(void);
		void	assign_data(void);
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_phone_number(void);
		std::string	get_darkest_secret(void);
		void	get_contact_infos(void);
		void	desplay_phonebook_contacts(void);
};


#endif