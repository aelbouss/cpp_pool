#include <iostream>
#include <limits>

# ifndef CONTACT_HPP
# define CONTACT_HPP

// class section

class	Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string	nickname;
		std::string phone_number;
		std::string	darkest_secret;
	public:

		void	assign_data(void);
		void	desplay_contact_infos(int idx);
		std::string	get_name(void);
		void	proper_desplay(std::string field, bool flag);
};


//  methods sections :

void	Contact::assign_data(void)
		{
			std::cin.ignore();
			while (true)
			{
				std::cout << "Enter First Name : ";
				getline(std::cin ,first_name);
				if (!first_name.empty())
					break ;
				else
					std::cout << "The First Name Cannot Be Empty" << std::endl;
			}
			std::cin.ignore();
			while (true)
			{
				std::cout << "Enter Last Name : ";
				getline(std::cin, last_name);
				if (!last_name.empty())
					break ;
				else
					std::cout << "The Last Name Cannot Be Empty" << std::endl;
			}
			std::cin.ignore();
			while (true)
			{
				std::cout << "Enter The NickName : ";
				getline(std::cin, nickname);
				if (!nickname.empty())
					break ;
				else
					std::cout << "The NickName Cannot Be Empty" << std::endl;
			}
			std::cin.ignore();
			while (true)
			{
				std::cout << "Enter Darkest Secret : ";
				getline(std::cin, darkest_secret);
				if (!darkest_secret.empty())
					break ;
				else
					std::cout << "The Darkest Secret Cannot Be Empty" << std::endl;
			}
		}


void	Contact::proper_desplay(std::string field, bool flag)
{
	int	i;

	i = 0;
	while (field[i])
	{
		if (i > 8)
		{
			std::cout << ".";
			break ;
		}
	}
	std::cout << "	";
	if (flag == true)
		std::cout << "|";
}

void	Contact::desplay_contact_infos(int idx)
{
			std::cout << idx  << "	|";
			proper_desplay(first_name, true);
			proper_desplay(last_name, true);
			proper_desplay(nickname, false);
			//std::cout << "|"<< last_name;
			//std::cout << "|"<< nickname << std::endl;
}

std::string	Contact::get_name(void)
{
			return (first_name);
}


#endif