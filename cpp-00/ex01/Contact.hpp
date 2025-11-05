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

// class section

void	eof_handling(void);
void	put_str_8_chars(std::string s);

class	Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string	nickname;
		std::string phone_number;
		std::string	darkest_secret;
	public:

	   // setters
		void	take_first_name(void);
		void	take_last_name(void);
		void	take_nick_name(void);
		void	take_phone_number(void);
		void	take_darkest_secret(void);
		void	assign_data(void);
		// getters
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_phone_number(void);
		std::string	get_darkest_secret(void);
		// utilities 
		void	get_contact_infos(void);
		void	desplay_phonebook_contacts(void);
};


/* =>  setters section  <= */


void	Contact::take_first_name(void)
{
	do
	{
		std::cout << "enter the first name : ";
		getline(std::cin, first_name);
		eof_handling();
		if (first_name.empty())
			std::cout << "the filed cannot be empty tray again" << std::endl;
		if (!first_name.empty())
			break ;
	}while(1);
}

void	Contact::take_last_name(void)
{
	do
	{
		std::cout << "enter the last name : ";
		getline(std::cin, last_name);
		eof_handling();
		if (last_name.empty())
			std::cout << "the filed cannot be empty tray again" << std::endl;
		if (!last_name.empty())
			break ;
	}while(1);
}

void	Contact::take_nick_name(void)
{
	do
	{
		std::cout << "enter the nick name : ";
		getline(std::cin, nickname);
		eof_handling();
		if (nickname.empty())
			std::cout << "the filed cannot be empty tray again" << std::endl;
		if (!nickname.empty())
			break ;
	}while(1);	
}

void	Contact::take_phone_number(void)
{
	do
	{
		std::cout << "enter the phone number : ";
		getline(std::cin, phone_number);
		eof_handling();
		if (phone_number.empty())
			std::cout << "the filed cannot be empty tray again" << std::endl;
		if (!phone_number.empty())
			break ;
	}while(1);		
}

void	Contact::take_darkest_secret(void)
{
	do
	{
		std::cout << "enter the darkest secret : ";
		getline(std::cin, darkest_secret);
		eof_handling();
		if (darkest_secret.empty())
			std::cout << "the filed cannot be empty tray again" << std::endl;
		if (!darkest_secret.empty())
			break ;
	}while(1);	
}

void	Contact::assign_data(void)
{
	take_first_name();
	take_last_name();
	take_phone_number();
	take_nick_name();
	take_darkest_secret();
}

/* =>  geters  <= */

std::string	Contact::get_first_name(void)
{
	return (first_name);
}

std::string	Contact::get_last_name(void)
{
	return (last_name);
}

std::string	Contact::get_nickname(void)
{
	return (nickname);
}

std::string	Contact::get_phone_number(void)
{
	return (phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (darkest_secret);
}

void	Contact::get_contact_infos(void)
{
	std::cout << "the first name : " << get_first_name() << std::endl;
	std::cout << "the last name : " << get_last_name() << std::endl;
	std::cout << "the nickname : " << get_nickname() << std::endl;
	std::cout << "the phone number : " << get_phone_number() << std::endl;
	std::cout << "the darest secret : " << get_darkest_secret() << std::endl;
}

void	put_str_8_chars(std::string s)
{
	int	i;

	i = 0;
	while (s[i] && i < 9)
	{
		std::cout << s[i];
		i++;
	}
	if (s[i])
		std::cout << '.';
}

/*

Idx  First Name     Last Name      Nickname       
-----------------------------------------------
1    Alice          Johnson        Ally           
2    Bob            Smith          Bobby          
3    Charlie        Brown          Chuck          
4    Diana          Prince         Wonder       

*/

/*
 cout << left 
         << setw(wIdx)  << "Idx"
         << setw(wFirst) << "First Name"
         << setw(wLast)  << "Last Name"
         << setw(wNick)  << "Nickname" 
         << endl;

*/



void	Contact::desplay_phonebook_contacts(void)
{
	std::cout << std::right
	<< std::setw(15); put_str_8_chars(get_first_name()) ; std::cout << " |"
	<< std::setw(15); put_str_8_chars(get_last_name()) ; std::cout << " |"
	<< std::setw(15); put_str_8_chars(get_nickname()) ; std::cout << " |" << std::endl;
}


#endif