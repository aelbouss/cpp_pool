#include "sed_for_losers.hpp"


int check_substr_existance(const char *filename, const char *substr)
{
    std::string line;

    if (!substr || !filename)
        return (1);
    
    std::ifstream infile(filename);
    if (!infile)
    {
        std::cerr << "error occurs while open a file" << std::endl;
        return (1);
    }
    while (std::getline(infile, line))
    {
        if (line.find(substr) !=  std::string::npos)
            return (0);
    }
    std::cerr << "the substr : "<< substr << " not found" << std::endl;
    return (1);
}

int replace_str(char *str , char *substr, char *newstr)
{
    size_t  pos;

    if (!substr || !newstr || !str)
        return (1);
    std::string sub_str(sub_str);
    std::string new_str(newstr);
    std::string mainstr(str);
    while ((pos = ))    //  replace  the old str
}

int costume_sed(char *readfile, char *substr, char *rep)
{
    std::ifstream infile;
    std::ofstream outfile;
    std::string newfile;
    std::string line;
    int pos;

    if (!rep || !infile)
    {
        std::cout << "invalid arguments" << std::endl;
        return (1);outfile.open(newfile.c_str(), std::ios::out);
    }
    infile.open(readfile, std::ios::in);
    if (!infile.is_open())
    {
        std::cerr << "error occurs while opening the file : " << readfile << std::endl;
        return (1);
    }
    outfile.open(newfile.c_str(), std::ios::out);
    if (!outfile.is_open())
    {
        std::cerr << "error occurs while creating the file" << std::endl;
        return (1);
    }

    while (std::getline(infile, line))
    {

    }
}