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

int copy_content(char *oldfile)
{
    std::ofstream outfile;
    std::ifstream infile;
    std::string newfile;
    std::string line;

    if (!oldfile)
    {
        std::cerr << "Bad file" << std::endl;
        return (1);
    }
    infile.open(oldfile, std::ios::in);
    if (!infile.is_open())
    {
        std::cerr << "error occurs while creating the file" << std::endl;
        return (1);  
    }
    newfile = std::string(oldfile) + ".replace";

    outfile.open(newfile.c_str(), std::ios::out);
    if (!outfile.is_open())
    {
        std::cerr << "error occurs while creating the file" << std::endl;
        return (1);
    }
     while (std::getline(infile, line))
     {
        outfile << line << '\n';   // add newline back
    }
    return (0);
}
