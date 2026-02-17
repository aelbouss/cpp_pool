# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"

class ShrubberyCreationForm :public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm(std::string Target);
		ShrubberyCreationForm(ShrubberyCreationForm& src);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm& src);
		std::string	get_target_name(void) const ;
		void	perform_task() const;
		~ShrubberyCreationForm();
};

# endif