/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flex <flex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:16:08 by aelbouss          #+#    #+#             */
/*   Updated: 2026/05/28 14:17:18 by flex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <bits/stdc++.h>
# include <cstring>
# include <algorithm>
# include <sstream>

class	BitcoinExchange
{
	private:
		std::map<std::string, float> db_container;
 	public:
		BitcoinExchange();
		BitcoinExchange&	operator = (const BitcoinExchange& src);
		BitcoinExchange(const BitcoinExchange& src);
		~BitcoinExchange();
		void	parse_db_file(void);
        void    parse_input(std::string file);
	    void	parse_value(void);
        bool 	parse_date(std::string date);
};





# define  RED "\e[0;31m"
# define  RESET "\e[0m"
# define GREEN "\e[0;32m"
# define YELLOW	"\e[0;33m"

# endif
