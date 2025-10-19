#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"


void	phonebook_start(void)
{
	std::cout << "********************************************************" << std::endl;
	std::cout << "********************************************************" << std::endl;
	std::cout << "*********** Welcome To The 80's E-Phonebook ************" << std::endl;
	std::cout << "********************************************************" << std::endl;
	std::cout << "********************************************************" << std::endl;
	std::cout << "\n\n";
}

int	main(void)
{

	PhoneBook	myphonebook;
	std::string	option, fname;
	int	status;

	status  = 0;
	myphonebook.reset_idx();
	phonebook_start();
	do
	{
		std::cout << "menu : " << std::endl;
		std::cout << "add contact =>   1 " << std::endl;
		std::cout << "search For Contact " << std::endl;
		std::cout << "menu : " << std::endl;
		std::cout << "choose the option : ";
		std::cin >> option;
		if (option == "ADD")
			myphonebook.add_contact();
		if (option == "SEARCH")
		{
			std::cout<< "enter the first name : ";
			std::cin >> fname;	
			myphonebook.search_for_contact(fname);
		}
		if (option == "EXIT")
			status = 1;
	} while (status != 1);

	myphonebook.get_all_arr();
	return (0);
}