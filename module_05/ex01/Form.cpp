# include "Form.hpp"

Form::Form() :name("NOform")
{
	this->grade_e = 0 ;
	this->grade_s = 0 ;
	this->is_signed = false ;
}

Form::Form(std::string Name, int Grade_sign, int Grade_exec) :name(Name)
{
	if (Grade_sign < 1)
		throw Form::GradeTooHighException();
	if (Grade_exec < 1)
		throw Form::GradeTooHighException();
	if (Grade_sign > 150)
		throw Form::GradeTooLowException();
	if (Grade_exec > 150)
		throw Form::GradeTooLowException();
	is_signed = false;
	grade_s = Grade_sign;
	grade_e = Grade_exec;
}

Form::Form(const Form& src)
{
	(*this) = src ;
}
Form&	Form::operator=(const Form& src)
{
	if (this == &src)
		return (*this);
	this->grade_e = src.grade_e;
	this->grade_s = src.grade_s;
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
	os <<  "Name : " << f.get_name( ) << " sign flag : " << f.get_form_status() << " sign grade : " << 
		f.get_sign_grade() << " execute grade : " << f.get_execute_grade() << std::endl;
	return (os);
}

void	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= grade_s)
		is_signed = true;
	else
	{
		std::cerr <<"Bureacucrat : "<< b.getName() << " couldn't sign : " << this->get_name() << "  because : " ;
		throw Form::GradeTooLowException();
	}
}

bool	Form::get_form_status(void) const
{
	return (is_signed);
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Form's Grade Is Too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form's Grade Is Too Low") ;
}