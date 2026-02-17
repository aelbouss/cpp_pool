# include  "GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException(int Grade) :grade(Grade){}

std::string GradeTooHighException::what()
{
	return ("The Grade Is Too High");
}

GradeTooHighException::~GradeTooHighException() throw() {}