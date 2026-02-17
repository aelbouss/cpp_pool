# ifndef GRADETOOHIGHEXCEPTION_HPP
# define GRADETOOHIGHEXCEPTION_HPP

# include  "Bureaucrat.hpp"


class	GradeTooHighException :public std::exception
{
	private:
		int	grade;
	public:
		GradeTooHighException(int grade);
		virtual ~GradeTooHighException() throw();
		const char* what() const throw();
};

# endif