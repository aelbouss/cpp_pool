# ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	private:
		std::string name;
		bool	is_signed;
		int grade_s;
		int grade_e;
	public:
		Form();
		Form(std::string Name, const int Grade_sign, const int Grade_exec);
		Form(const Form& src);
		Form&	operator=(const Form& src);
		~Form();
		int		get_sign_grade(void) const;
		int		get_execute_grade(void) const ;
		std::string	get_name(void) const ;
		bool	get_form_status(void) const ;
		void	beSigned(Bureaucrat& b); // here

		class	GradeTooHighException :public std::exception
		{
			private:
				int	grade;
			public:
				GradeTooHighException(int grade);
				virtual ~GradeTooHighException() throw();
				const char	*what() const throw() ;
		};

		class GradeTooLowException :public std::exception
		{
			private:
				int	grade;
			public:
				GradeTooLowException(int Grade);
				virtual ~GradeTooLowException() throw();
				const char	*what() const throw() ;
		};

};

std::ostream&	operator << (std::ostream& os , const Form& f);

# endif
