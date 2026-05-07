#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data(), _input() {}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::loadData() {
    std::ifstream infile("data.csv");

    if (!infile.is_open())
        throw std::runtime_error("could not open file");

    std::string line;
    while (std::getline(infile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = line.substr(0, commaPos);
            float value = std::atof(line.substr(commaPos + 1).c_str());
            _data.insert(std::make_pair(date, value));
        }
    }
    infile.close();
}

void BitcoinExchange::processInput(const char* file) {
    std::ifstream infile(file);
    if (!infile.is_open())
        throw std::runtime_error("could not open file");
    std::string line;
    while (std::getline(infile, line))
    {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) 
        {
            std::string date = line.substr(0, commaPos);
            float value = std::atof(line.substr(commaPos + 1).c_str());
            _input.insert(std::make_pair(date, value));
        }
    }
    infile.close();
}