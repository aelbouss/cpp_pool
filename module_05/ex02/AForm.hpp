# ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
	private:
		std::string name;
		bool	is_signed;
		bool	is_executed;
		int grade_s;
		int grade_e;
	public:
		AForm();
		AForm(std::string Name, const int Grade_sign, const int Grade_exec);
		AForm(const AForm& src);
		AForm&	operator=(const AForm& src);
		virtual ~AForm();
		int		get_sign_grade(void) const;
		int		get_execute_grade(void) const ;
		std::string	get_name(void) const ;
		friend std::ostream&	operator << (std::ostream& os , const AForm& f);
		bool	get_form_status(void) const ;
		bool	get_execution_status(void) const ;
		void	beSigned(Bureaucrat& b);
		void	execute(Bureaucrat const & executor) const;
		virtual	void	perform_task(void) const = 0;

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
