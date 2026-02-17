# include "GradeTooLowException.hpp"

GradeTooLowException::GradeTooLowException(int Grade) :grade(Grade){}

const char*	GradeTooLowException::what() const throw()
{
	std::cerr << "The Grade : "<< grade;
	return (" Is Too Low");
}

GradeTooLowException::~GradeTooLowException() throw() {}