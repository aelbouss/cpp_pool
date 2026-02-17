# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"

class PresidentialPardonForm :public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm(std::string Target);
		PresidentialPardonForm&	operator = (const PresidentialPardonForm& src);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		std::string	get_target_name()const;
		void	perform_task() const;
		~PresidentialPardonForm();
};


# endif