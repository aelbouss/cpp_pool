#include "Contact.hpp"
#include "PhoneBook.hpp"

void	phonebook_options(void)
{
		std::cout << "\n";
		std::cout << RED << "*************************************************" << std::endl;
		std::cout << "*                Operations                     *" << std::endl;
		std::cout << "*                                               *" << std::endl;
		std::cout << "*    ==>    add a contact => ADD                *" << std::endl;
		std::cout << "*    ==>    search about a contact => SEARCH    *" << std::endl;
		std::cout << "*    ==>    exit the program => EXIT            *" << std::endl;
		std::cout << "*************************************************" << RESET << std::endl;
}


int	main(void)
{

	PhoneBook	myphonebook;
	std::string	option, fname;
	int	status;

	status  = 0;
	myphonebook.idx_init();
	do
	{
		phonebook_options();
		std::cout << "\n\nChoose an option : ";
		std::cin >> std::ws;
		if (std::cin.eof())
		{
				std::cout << "\nEOF\n";
				exit (0);
		}
		std::cin >> option;
		if (option == "ADD")
			myphonebook.add_contact();
		else if (option == "SEARCH")
		{
			std::cin.ignore();
			while (true)
			{
				std::cout << "Enter The UserName : ";
				getline(std::cin, fname);
				if (std::cin.eof())
				{
					std::cout << "\nEOF\n";
					exit(0);
				}
			
				if (!fname.empty())
					break ;
			}
			myphonebook.search_for_contact(fname);
		}
		else if (option == "EXIT")
			status = 1;
		else
			std::cout <<  GREEN << "\n Invalid Option ! Try Again "<< RESET << std::endl;
	}while (status != 1);

	return (0);
}