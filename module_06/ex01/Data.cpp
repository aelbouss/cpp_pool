# include "Data.hpp"

	Data::Data() {str = ""; }

	Data::Data(std::string s) :str(s){}

	Data&	Data::operator = (const Data& o)
	{
		if (this != &o)
			this->str = o.str;
		return *this;
	}

	Data::Data(const Data& o){ *this = o; }

	Data::~Data() {};

	std::string Data::get_str() { return str; }

	void	Data::set_str(std::string s) { this->str = s; } 