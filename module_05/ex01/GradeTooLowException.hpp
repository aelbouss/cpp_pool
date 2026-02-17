# ifndef GRADETOOLOWEXCEPTION_HPP
# define GRADETOOLOWEXCEPTION_HPP

# include "Bureaucrat.hpp"

class GradeTooLowException
{
	private:
		int	grade;
	public:
		GradeTooLowException(int Grade);
		virtual ~GradeTooLowException() throw();
		const char* what() const throw();
};


# endif
