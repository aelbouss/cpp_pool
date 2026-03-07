# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat b1(11 , "anass");
			std::cout << b1 << std::endl;
			b1.increment();
			Form f1("F1-FF", 10 , 9);
			b1.signForm(f1);

		}
		catch (const std::exception &e)
		{
			std::cerr << "exception caught : " << RED << e.what() << RESET << std::endl;
		}
	}
	std::cout << "\n";
	{
		try
		{
			Bureaucrat b1(14, "anass");
			Form f1("F1-FF", 10 , 9);
			b1.signForm(f1);
		}
		catch (const std::exception &e)
		{
			std::cerr << "exception caught : " << RED << e.what() << RESET << std::endl;
		}
	}
	
	return (0);
}