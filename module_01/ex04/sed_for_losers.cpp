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

int replace_str(std::string& main_str  , char *substr, char *newstr)
{
    size_t  pos;

    if (!substr || !newstr || main_str.empty())
        return (1);
    std::string sub_str(substr);
    std::string new_str(newstr);
    pos = 0;
    while ((pos = main_str.find(sub_str, pos)) != std::string::npos) 
    {
        main_str.erase(pos, main_str.length());
        main_str.insert(pos, new_str);
        pos++;
    } 
    return (0);
}

int costume_sed(char *readfile, char *substr, char *rep)
{
    std::ifstream infile;
    std::ofstream outfile;
    std::string newfile;
    std::string line;


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
    newfile = std::string(readfile) + ".replace";
    outfile.open(newfile.c_str(), std::ios::out);
    if (!outfile.is_open())
    {
        std::cerr << "error occurs while creating the file" << std::endl;
        return (1);
    }

    while (std::getline(infile, line))
    {
        std::cout << " line before : => " << line << std::endl;
        replace_str(line, substr, rep);
        std::cout << " line after : => " << line << std::endl;
        outfile << line << '\n';

    }
    return (0);
}