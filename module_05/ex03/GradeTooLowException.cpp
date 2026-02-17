# include "GradeTooLowException.hpp"

GradeTooLowException::GradeTooLowException(int Grade) :grade(Grade){}

std::string	GradeTooLowException::what()
{
	return "The grade Is Too Low" ;
}

GradeTooLowException::~GradeTooLowException() throw() {}