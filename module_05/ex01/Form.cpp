# include "Form.hpp"

Form::Form(std::string Name, int Grade_sign, int Grade_exec) :  name(Name) , grade_s(Grade_sign) , grade_e(Grade_exec)
{
	if (Grade_sign < 1)
		throw GradeTooHighException(Grade_sign);
	if (Grade_exec < 1)
		throw GradeTooHighException(Grade_exec);
	if (Grade_sign > 150)
		throw GradeTooLowException(Grade_sign);
	if (Grade_exec > 150)
		throw GradeTooLowException(Grade_exec);
	is_signed = false;
}

Form::Form(const Form& src) :  name(src.name) , grade_s(src.grade_s) , grade_e(src.grade_e)
{
}
Form&	Form::operator=(const Form& src)
{
	 this->is_signed = src.is_signed;
	return (*this);
}

Form::~Form(){}

int	Form::get_sign_grade(void) const
{
	return(grade_s); 
}

int	Form::get_execute_grade(void) const
{
	return (grade_e);
}

std::string	Form::get_name(void) const
{
	return (name);
}

std::ostream&	operator << (std::ostream& os , const Form& f)
{
	os << "Name : " << f.get_name( ) << "grade signed : " << 
		f.get_sign_grade() << "grade execute : " << f.get_execute_grade();
	return (os);
}

void	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= grade_s)
		is_signed = true;
}

bool	Form::get_form_status(void) const
{
	return (is_signed);
}


