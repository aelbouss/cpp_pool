#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"


void	phonebook_options(void)
{
	std::cout << "********************************************************" << std::endl;
	std::cout << "* 													 *" << std::endl;
	std::cout << "*********** Welcome To The 80's E-phonebook ************" << std::endl;
	std::cout << "*                                                      *" << std::endl;
	std::cout << "********************************************************" << std::endl;
	std::cout << "\n\n";
	std::cout << "you have to  choose of of  those bello options" << std::endl;
	std::cout << "ADD => to add new contact" << std::endl;
	std::cout << "SEARCH => to search for a contact" << std::endl;
	std::cout << "EXIT => to exit from the program" << std::endl;
}

int	main(void)
{

	PhoneBook	myphonebook;
	std::string	option, fname;
	int	status;

	status  = 0;
	myphonebook.reset_idx();
	do
	{
		phonebook_options();
		std::cout << "enter the option : " << std::endl;
		std::cin >> option;
		if (option == "ADD")
			myphonebook.add_contact();
		if (option == "SEARCH")
		{
			std::cout<< "enter the first name : "<<std::endl;
			std::cin >> fname;	
			myphonebook.search_for_contact(fname);
		}
		if (option == "EXIT")
			status = 1;
	} while (status != 1);

	return (0);
}