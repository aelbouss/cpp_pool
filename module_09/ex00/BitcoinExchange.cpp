# include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{

}


BitcoinExchange&  BitcoinExchange::operator = (const BitcoinExchange& src)
{
	if (this != &src)
	{
		this->db_container = src.db_container;
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
 * @brief parse databse file extract date and exchange value
 * @param takes nothing
 * @return returns nothing
 */

short   count_separators(std::string date)
{
    size_t i = 0;
    short cnt = 0;

    while (date[i])
    {
        if (date[i] == '-')
            cnt++;
        i++;
    }
    return cnt;
}

bool    check_valid_chars(std::string str)
{
    for (size_t i = 0 ; i < str.length() ; i++)
    {
        if ((str[i] < '0' || str[i] > '9') && (str[i] != '-') && (str[i] != ',') && (str[i] != '.'))
        {
            return false;
        }
    }
    return true ;
}

/**
 * @brief parse all the date detailes
 * @param the date should be parsed
 * @return nothing
 */

bool 	BitcoinExchange::parse_date(std::string date)
{
    short   day;
    short   month;
    short   year;
    std::vector <std::string> tokens;

    if (count_separators(date) != 2)
        return false;
    tokens = split(date, '-');
    year = atoi(tokens[0].c_str());
    month = atoi(tokens[1].c_str());
    day = atoi(tokens[2].c_str());

    if (year < 2009 || year > 2022)
        return false;
    if (month < 1 || month > 12)
        return false ;
    if (day < 1 || day > 31)
        return false ;
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
    {

        if ((month == 2) && (day < 1 || day > 29))
            return false ;
    }
    else
    {
        if ((month == 1) && ( day < 1 || day > 31))
            return false ;
        if ((month == 2) && (day < 1 || day > 28))
            return false ;
        if ((month == 3) && (day < 1 || day > 31))
            return false ;
        if ((month == 4) && (day < 1 || day > 30))
            return false ;
        if ((month == 5) && (day < 1 || day > 31))
            return false ;
        if ((month == 6) && (day < 1 || day > 30))
            return false ;
        if ((month == 7) && (day < 1 || day > 31))
            return false ;
        if ((month == 8) && (day < 1|| day > 31))
            return false ;
        if ((month == 9) && (day < 1 || day > 30))
            return false ;
        if ((month == 10) && (day < 1 || day > 31))
            return false ;
        if ((month == 11) && (day < 1 || day > 30))
            return false ;
        if ((month == 12) && (day < 1 || day > 31))
            return false ;
    }
    return true ;
}

bool    check_input_valid_chars(std::string str)
{
    for (size_t i = 0 ; i < str.length() ; i++)
    {
        if ((str[i] < '0' || str[i] > '9') && (str[i] != '.') && (str[i] != '-'))
        {
            return false;
        }
    }
    return true ;
}


/**
 * @brief parse the database
 * @param takes nothing
 * @return nothing
 */

void	BitcoinExchange::parse_db_file(void)
{
	std::string     Buffer;
	std::string     date;
	std::string     s_value;
    float           value;
	std::fstream    infile("data.csv");

	if (!infile)
        throw std::runtime_error("Couldn't Open DataBase File");
	while (getline(infile, Buffer))
	{
        size_t	idx = Buffer.find(",");
		if (idx == std::string::npos)
            throw std::runtime_error("Error : Bad database entries");
		date = Buffer.substr(0, idx);
		s_value = Buffer.substr(idx + 1 , Buffer.length() - 1);
        if (date == "date")
            continue ;
        if (!check_valid_chars(Buffer))
        {
            std::cout << Buffer << std::endl;
            throw std::runtime_error("Error : Bad DataBase entries");
        }
        parse_date(date);
        std::stringstream   ss(s_value.c_str());
        ss >> value ;
		db_container.insert(std::make_pair(date, value));
	}
    infile.close();

    /*   the print statement */
    /* td::map<std::string, float>::iterator it = db_container.begin();
   while (it != db_container.end())
    {
        std::cout << GREEN << "the date : "<< it->first << RED << " value : " << it->second << std::endl;
        it++;
    }*/
}


/**
* @brief parse the input file content
* @param the file should be parsed
* @return nothing
*/

void    BitcoinExchange::parse_input(std::string file)
{
    std::string date;
    std::string value ;
    float       f_value;
    std::string Buffer;
    float       res;
    float       exchange_rate;
    std::map<std::string, float>::iterator it;
    std::fstream   infile(file.c_str());

    if (!infile)
        throw std::runtime_error("Couldn't Open Input File");
    while (getline(infile, Buffer))
    {
        size_t  idx = Buffer.find("|");
        if (idx == std::string::npos)
        {
            std::cerr << "bad input => " << Buffer << std::endl;
            continue;
        }
        date = Buffer.substr(0, idx); 
        remove_start_spaces(date);
        remove_end_spaces(date);
        if (date == "date")
            continue ;
        if (!check_input_valid_chars(date))
            throw std::runtime_error("Error : Bad Input File Entries");
        if (!parse_date(date))
        {  
            std::cerr << "bad input => " << date << std::endl;
            continue;
        }
        value = Buffer.substr(idx + 1, Buffer.length() - 1);
        remove_start_spaces(value);
        remove_end_spaces(value);  
        std::stringstream ss(value.c_str()); 
        if (!(ss >> f_value) || !ss.eof() || ! check_input_valid_chars(value))
        {
            std::cerr << "bad input => "<< value << std::endl;
            continue ;
        } 
        it = db_container.find(date);
        if (it != db_container.end())
        { 
            exchange_rate = it->second;
        }
        else
        {
            it = db_container.upper_bound(date);
            --it;
            exchange_rate = it->second;
        }
        if (f_value < 0)
        {
            std::cerr << "Error : not a positive number" << std::endl;
            continue;
        }
        else if (f_value > 1000)
        {
            std::cerr << "Error : too large a number" << std::endl;
            continue ;
        }
        else
        {
            res = f_value * exchange_rate;
            std::cout << date << " => " << f_value << " = " << res << std::endl;
        }
    }
    infile.close();
}
