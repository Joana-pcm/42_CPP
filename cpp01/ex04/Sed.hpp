#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Sed
{
private:
	std::string _infile;
	std::string _outfile;

public:
	Sed();
	Sed(std::string infile);
	~Sed();
	void replaceInFile(std::string s1, std::string s2) const;
};