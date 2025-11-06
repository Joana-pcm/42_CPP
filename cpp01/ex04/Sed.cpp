#include "Sed.hpp"

Sed::Sed() : _infile(""), _outfile("") {}

Sed::Sed(std::string infile)
	: _infile(infile) {
		this->_outfile = infile.append(".replace");
	}

Sed::~Sed() {}

void Sed::replaceInFile(std::string s1, std::string s2) const {
	std::ifstream infile(_infile.c_str());
	std::string line;
	size_t pos;

	if (!infile || infile.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "Could not open file or file is empty.\n";
		return ;
	}
	if (s1.empty() || s2.empty()) {
		std::cout << "String to replace is empty.\n";
		return ;
	}
	std::ofstream outfile(_outfile.c_str());
	while (std::getline(infile, line)) {
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line << "\n";
	}
	outfile.close();
	infile.close();
}