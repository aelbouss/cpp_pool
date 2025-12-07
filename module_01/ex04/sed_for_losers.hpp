# ifndef SED_FOR_LOSERS_HPP
# define SED_FOR_LOSERS_HPP

// headers sectino

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
 
 // prototypes  section

int check_substr_existance(const char *filename, const char *substr);
int replace_str(std::string& main_str  , char *substr, char *newstr, int firststr_len);
int costume_sed(char *readfile, char *substr, char *rep);

# endif