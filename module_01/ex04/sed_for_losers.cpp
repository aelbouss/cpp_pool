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

int find_replace(char *substr, char *substitution, char *filename)
{
    std::string line;
    std::string newfile;
    std::string extension;

    std::ifstream infile(filename);
    if (!infile)
    {
        std::cerr << "error occurs while open a file" << std::endl;
        return (1);
    }
    extension = ".replace";
    newfile = filename + extension;
    std::ifstream outfile(newfile);
    if (!outfile)
    {
        std::cerr << "error occurs while open the file: " << newfile << std::endl;
        return (1);
    }
    while (std::getline(filename, line))
    {
        if (line.find(substr) != std::string::npos)
        {
            //  replace a string  in  a line .
        }
    }
}