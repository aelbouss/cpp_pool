# include  "GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException(int Grade) :grade(Grade){}

const char*	GradeTooHighException::what()  const throw()
{
	std::cerr << "The Grade : "<< grade ;
	return (" Is Too High");
}

GradeTooHighException::~GradeTooHighException() throw() {}