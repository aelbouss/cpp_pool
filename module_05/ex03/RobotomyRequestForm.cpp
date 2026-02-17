# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string Target) :AForm("RobotomyRequestForm", 72, 45)
{
	target = Target;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	AForm::operator=(src);
	this->target = src.target;
	return (*this);
}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& src) :AForm("RobotomyRequestForm", 72, 45)
{
	this->target = src.target;
}
std::string	RobotomyRequestForm::get_target_name(void) const { return(target); }


void	RobotomyRequestForm::perform_task(void) const
{
	std::cout << "VRRRRRRRRRRRRRRRRRRRR..." << std::endl;
	srand(time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << this->target + "has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}