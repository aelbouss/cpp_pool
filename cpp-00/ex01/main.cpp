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

void	eof_handling(void)
{
	if (std::cin.eof())
	{
			std::cout << "\nEOF\n";
			exit (0);
	}
}

int	main(void)
{
	PhoneBook	myphonebook;
	std::string	option;

	myphonebook.set_idx();
	do
	{
		phonebook_options();
		std::cout << "choose an option : ";
		getline(std::cin, option);
		eof_handling();
		if (option == "ADD")
			myphonebook.add_contact();
		else if(option == "SEARCH")
		{
			myphonebook.search_for_contact();
		}
		else if (option == "EXIT")
		{
			std::cout << "exit\n";
		}
		else
		{
			if (option.empty())
				std::cout << "\nthe  filed  cannot  be  empty\n" << std::endl;
			if (!option.empty() && option != "ADD" && option != "SEARCH" &&  option != "EXIT")
				std::cout << "\nunavailable option tray agian\n" << std::endl;
		}
	} while (1);
	return (0);
}