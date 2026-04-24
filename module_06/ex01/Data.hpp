# ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class	Data
{
	private:
		std::string str;
	public:
		Data();
		Data(std::string s);
		Data&	operator = (const Data& o);
		Data(const Data& o);
		~Data();
		std::string get_str();
		void	set_str(std::string s);
};

# endif