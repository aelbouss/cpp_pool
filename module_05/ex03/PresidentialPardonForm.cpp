# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string Target) :AForm("PresidentialPardonForm", 25, 5)
{
	target = Target;
}
PresidentialPardonForm&	PresidentialPardonForm::operator = (const PresidentialPardonForm& src)
{
	AForm::operator=(src);
	this->target = src.target;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) :AForm("PresidentialPardonForm", 25, 5)
{
	this->target = src.target;
}
std::string	PresidentialPardonForm::get_target_name()const { return (target); }

void	PresidentialPardonForm::perform_task(void) const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}