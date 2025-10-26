#include <iostream>
#include <limits>
#include <cstdlib>

# ifndef CONTACT_HPP
# define CONTACT_HPP

// macros 

# define RED "\033[1;31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"

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
		void	desplay_contact_infos(int idx, Contact *contacts);
		std::string	get_name(void);
		void	proper_desplay(std::string field, bool flag);
		void	just_print();
};


//  methods sections
void	Contact::assign_data(void)
		{
			std::cin.ignore();
			while (true)
			{
				std::cout << "Enter First Name : ";
				getline(std::cin ,first_name);
				if (std::cin.eof())
				{
					std::cout << "\nEOF\n";
					exit (0);
				}
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
				if (std::cin.eof())
				{
					std::cout << "\nEOF\n";
					exit (0);
				}
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
				if (std::cin.eof())
				{
					std::cout << "\nEOF\n";
					exit (0);
				}
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
				if (std::cin.eof())
				{
					std::cout << "\nEOF\n";
					exit (0);
				}
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
	std::cout << "	";
	while (field[i])
	{
		if (i > 8)
		{
			std::cout << ".";
			break ;
		}
		else
			std::cout << field[i];
		i++;
	}
	if (flag == true)
		std::cout << "|";
}

void	Contact::desplay_contact_infos(int idx, Contact *contacts)
{
			std::cout << "\n";
			std::cout<<"	"<< idx << "|";
			proper_desplay(contacts[idx].first_name, true);
			proper_desplay(contacts[idx].last_name, true);
			proper_desplay(contacts[idx].nickname, false);
			std::cout << "\n";
}

std::string	Contact::get_name(void)
{
			return (first_name);
}


#endif