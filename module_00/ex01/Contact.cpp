#include "Contact.hpp"

void	Contact::take_first_name(void)
{
	do
	{
		std::cout << "enter the first name : ";
		getline(std::cin, first_name);
		eof_handling();
		if (first_name.empty())
			std::cout << "the filed cannot be empty try again" << std::endl;
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
			std::cout << "the filed cannot be empty try again" << std::endl;
		if (!last_name.empty())
			break ;
	}while(1);
}

void	Contact::take_nick_name(void)
{
	do
	{
		std::cout << "enter the nickname : ";
		getline(std::cin, nickname);
		eof_handling();
		if (nickname.empty())
			std::cout << "the filed cannot be empty try again" << std::endl;
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
			std::cout << "the filed cannot be empty try again" << std::endl;
		if (validate_phonenumber(phone_number) != 0)
		{
			std::cout << "invalid phone number" << std::endl;
			std::cout << "< usage : +212... | OR |  06... > \n" << std::endl;
			continue;
		}
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
			std::cout << "the filed cannot be empty try again" << std::endl;
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
	std::cout << GREEN << "the first name : " << get_first_name() << std::endl;
	std::cout << "the last name : " << get_last_name() << std::endl;
	std::cout << "the nickname : " << get_nickname() << std::endl;
	std::cout << "the phone number : " << get_phone_number() << std::endl;
	std::cout << "the darest secret : " << get_darkest_secret() << RESET << std::endl;
}

void	put_str_8_chars(std::string str)
{
	if (str.length() > 10)
        str = str.substr(0, 9) + ".";
    std::cout << std::setw(10) << str;
}

int	validate_phonenumber(std::string str)
{
	if (str[0] != '+' && !isdigit(str[0]))
		return (1);
	for (size_t i = 1 ; i < str.length() ; i++)
	{
		if (!isdigit(str[i])) {return(1);}
	}
	return (0);
}

void	Contact::desplay_phonebook_contacts(void)
{
	put_str_8_chars(first_name);
    std::cout << "|";
    put_str_8_chars(last_name);
    std::cout << "|";
    put_str_8_chars(nickname);
    std::cout << "|\n";
}