# include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{

}


BitcoinExchange&  BitcoinExchange::operator = (const BitcoinExchange& src)
{
	if (this != &src)
	{
		this->db_Container = src.db_Container;
		this->in_container = src.in_container;	
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
}


BitcoinExchange::~BitcoinExchange()
{

}



/**
 * @brief parse database file extesnion
 * @param file the file name
 * @return true or false
 */

bool	parse_db_file(std::string file)
{
	std::string	extension = "csv";
	for (size_t end = file.length() - 1; end > end - 3 ; end--)
	{
		if (file[end] != file[end])
			return false;	
	}
	return true;
}


/**
 * @brief removes spaces from the end of  strings
 * @param str which is the string pased by reference
 * @return nothihg
 */


void	remove_end_spaces(std::string& str)
{
	size_t	last;

	last = str.find_last_not_of(" \t\n\r");
	if (last != std::string::npos)
		str.erase(last + 1);
	else
		str.clear();	
}

void	remove_start_spaces(std::string& str)
{
	str.erase(0, str.find_first_not_of(" \t\n\r"));
}


/**
 * @brief splits one string into many with using a separator
 * @param s the string should be splited
 * @param delimiter the separator used to split the string
 * @return vector contain tokens
 */

std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}


/**
 * @brief parse input file content : day, month , year
 * @param file	which is the file accepted from av
 * @return true or  false
 */


bool	BitcoinExchange::parse_db_file(std::string file)
{
	std::string	Buffer;
	std::string	key;
	std::string	value;
	std::fstream	infile(file.c_str());

	if (!infile)
	{
		std::cerr << RED << "Error : Couldn't open the input file !" << RESET << std::endl;
		return false;
	}
	while (getline(infile, Buffer))
	{
		size_t	idx = Buffer.find("|");
		if (idx == std::string::npos)
		{
			key = Buffer;
			remove_end_spaces(key);
			value = "0";
			in_container.insert(std::make_pair(key, value));
			continue ;	
		}
		key = Buffer.substr(0, idx);
		remove_end_spaces(key);	
		value = Buffer.substr(idx + 1 , Buffer.length() - 1);
		remove_start_spaces(value);
		in_container.insert(std::make_pair(key, value));
	}
	/*std::multimap<std::string, std::string>::iterator it;
	for (it = in_container.begin() ; it != in_container.end() ; ++it)
		std::cout << RED  << "Key => {" << it->first << "} " << RESET << GREEN  << "Value => {" << it->second << "}" << RESET << std::endl;*/
	return true;
}

bool	BitcoinExchange::parse_date()
{
	std::string	date;
	short		day;
	short 		month;
	short		year;
	std::vector<std::string> tokens;

	std::multimap<std::string, std::string>::iterator it = in_container.begin();
	while (it != in_container.end())
	{
		date = it->first;
		tokens = split(date, '-');
		day   = atoi(tokens[0].c_str());
		month = atoi(tokens[1].c_str());
		year  = atoi(tokens[2].c_str());
		std::cout << YELLOW  << day << RESET << std::endl;
		std::cout << YELLOW  << month << RESET << std::endl;
		std::cout << YELLOW  << year  << RESET << std::endl;
		std::cout << RED << "==================" << RESET << std::endl;
		++it;
	}
	return true;
}









/*bool	BitcoinExchange::arse_value();*/


