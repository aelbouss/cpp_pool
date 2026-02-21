# include "AForm.hpp"

AForm::AForm() {}

AForm::AForm(std::string Name, int Grade_sign, int Grade_exec)
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
	is_executed = false;
	name = Name;
	grade_s = Grade_sign;
	grade_e = Grade_exec;
}

AForm::AForm(const AForm& src)
{
	this->name = src.name;
	this->grade_e = src.grade_e;
	this->grade_s = src.grade_s;
	this->is_signed = src.is_signed;
	this->is_executed = src.is_signed;
}
AForm&	AForm::operator=(const AForm& src)
{
	if (this == &src)
		return (*this);
	this->name = src.name;
	this->grade_e = src.grade_e;
	this->grade_s = src.grade_s;
	this->is_signed = src.is_signed;
	this->is_executed = src.is_signed;
	return (*this);
}

AForm::~AForm(){}

int	AForm::get_sign_grade(void) const
{
	return(grade_s); 
}

int	AForm::get_execute_grade(void) const
{
	return (grade_e);
}

std::string	AForm::get_name(void) const
{
	return (name);
}

std::ostream&	operator << (std::ostream& os , const AForm& f)
{
	os << GREEN << "Name : " << f.get_name( ) << " grade signed : " << 
		f.get_sign_grade() << " grade execute : " << f.get_execute_grade() << RESET << std::endl;
	return (os);
}

void	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= grade_s)
		is_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > get_execute_grade())
	{
			std::cerr << "the form " << get_name() << " will not be executed : ";
			throw GradeTooLowException(executor.getGrade());
	}
}

bool	AForm::get_form_status(void) const
{
	return (is_signed);
}

bool	AForm::get_execution_status(void) const 
{
	return (is_executed);
}
