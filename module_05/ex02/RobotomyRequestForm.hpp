# ifndef ROBOTMYREQUESTFORM_HPP
# define ROBOTMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"

class RobotomyRequestForm :public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm(std::string Target);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& src);
		RobotomyRequestForm(RobotomyRequestForm& src);
		std::string	get_target_name(void) const;
		void	perform_task(void) const;
		~RobotomyRequestForm();
};

# endif