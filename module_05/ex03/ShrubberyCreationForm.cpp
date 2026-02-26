# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string Target) :AForm("ShrubberyCreationForm", 145, 137)
{
	target = Target;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm& src)
{
	AForm::operator=(src);
	this->target = src.target;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& src):AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = src.target;
}
std::string	ShrubberyCreationForm::get_target_name(void) const { return (target); }


void	ShrubberyCreationForm::perform_task(void) const
{
	std::string filename;

	filename = this->target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile.is_open())
		throw "Failed to open the shrubbery file";

   outfile << "                   &&& &&  & &&\n";
	outfile << "               && &\\/&\\|& ()|/ @, &&\n";
	outfile << "              &\\/(/&/&||/& /_/)_&/_&\n";
	outfile << "            &() &\\/&|()|/&\\/ '%\" & ()\n";
	outfile << "            &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
	outfile << "            &&  && & &| &| /& & % ()& /&&\n";
	outfile << "           ()&_---()&\\&\\|&&-&&--%---()~\n";
	outfile << "               &&     \\||| \n";
	outfile << "                        |||\n";
	outfile << "                        |||\n";
	outfile << "                        |||\n";
	outfile << "                  , -=-~  .-^- _\n";

	outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}