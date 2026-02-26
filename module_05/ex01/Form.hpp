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
		Form(std::string Name, const int Grade_sign, const int Grade_exec);
		Form(const Form& src);
		Form&	operator=(const Form& src);
		~Form();
		int		get_sign_grade(void) const;
		int		get_execute_grade(void) const ;
		std::string	get_name(void) const ;
		friend std::ostream&	operator << (std::ostream& os , const Form& f);
		bool	get_form_status(void) const ;
		void	beSigned(Bureaucrat& b);

		class	GradeTooHighException :public std::exception
		{
			private:
				int	grade;
			public:
				GradeTooHighException(int grade);
				virtual ~GradeTooHighException() throw();
				std::string	what();
		};

		class GradeTooLowException
		{
			private:
				int	grade;
			public:
				GradeTooLowException(int Grade);
				virtual ~GradeTooLowException() throw();
				std::string	what();
		};

};
# endif
