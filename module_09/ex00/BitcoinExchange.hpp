/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:16:08 by aelbouss          #+#    #+#             */
/*   Updated: 2026/05/16 00:50:35 by aelbouss         ###   ########.fr       */
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

class	BitcoinExchange
{
	private:
		std::multimap<std::string, std::string> db_Container;
		std::multimap<std::string, std::string> in_container;
 	public:
		BitcoinExchange();
		BitcoinExchange&	operator = (const BitcoinExchange& src);
		BitcoinExchange(const BitcoinExchange& src);
		~BitcoinExchange();
		bool	parse_db_file(std::string file);
		bool	parse_date();
		bool	parse_value();
};





# define  RED "\e[0;31m"
# define  RESET "\e[0m"
# define GREEN "\e[0;32m"

# endif
