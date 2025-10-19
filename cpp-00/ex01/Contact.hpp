#include <iostream>

# ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string	nickname;
		std::string phone_number;
		std::string	darkest_secret;
	public:

		void	assign_data(void)
		{
			std::cout << "first name : ";
			std::cin >> first_name;
			std::cout << "last name : ";
			std::cin >> last_name;
			std::cout << "nickname : ";
			std::cin >> nickname;
			std::cout << "darkest secret : ";
			std::cin >> darkest_secret;
		}
		void	desplay_contact_infos(int idx)
		{
			std::cout << idx ;
			std::cout << "|"<< first_name;
			std::cout << "|"<< last_name;
			std::cout << "|"<< nickname << std::endl;
		}

		std::string	get_name(void)
		{
			return (first_name);
		}
};

#endif