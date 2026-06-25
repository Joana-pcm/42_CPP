#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data(), _input() {}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::loadData() {
    std::ifstream infile("data.csv");

    if (!infile.is_open())
        throw std::runtime_error("could not open file");

    std::string line;
    if (!std::getline(infile, line))
        throw std::runtime_error("could not read file");
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
    if (!std::getline(infile, line))
        throw std::runtime_error("could not read file");
    while (std::getline(infile, line))
    {
        size_t commaPos = line.find(' ');
        if (commaPos != std::string::npos) 
        {
            std::string date = line.substr(0, commaPos);
            float value = std::atof(line.substr(commaPos + 3).c_str());
            _input.insert(std::make_pair(date, value));
        }
    }
    infile.close();
    loadData();
    validInput();
}

void BitcoinExchange::validInput() {
    int year = 0, month = 0, day = 0;
    
    for (std::map<std::string, float>::iterator iter = _input.begin() ;
         iter != _input.end(); iter++)
    {
        // Check basic format
        if (iter->first.length() != 10 
            || iter->first[4] != '-' || iter->first[7] != '-') {
            std::cout << "Error: bad input => " << iter->first << std::endl;
            continue ;
        }
        
        // Check value range
        if (iter->second < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue ;
        }
        if (iter->second > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue ;
        }
        
        // Check all characters are digits or dashes in correct positions
        bool valid = true;
        for (size_t i = 0; i < iter->first.length(); i++) {
            if (i == 4 || i == 7) {
                if (iter->first[i] != '-') {
                    valid = false;
                    break ;
                }
            } else if (!std::isdigit(iter->first[i])) {
                valid = false;
                break ;
            }
        }
        if (!valid) {
            std::cout << "Error: bad input => " << iter->first << std::endl;
            continue ;
        }
        
        year = std::atoi(iter->first.substr(0, 4).c_str());
        month = std::atoi(iter->first.substr(5, 2).c_str());
        day = std::atoi(iter->first.substr(8, 2).c_str());
        
        // Basic date validation
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            std::cout << "Error: bad input => " << iter->first << std::endl;
            continue ;
        }
        
        // Month-specific day limits
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
            std::cout << "Error: bad input => " << iter->first << std::endl;
            continue ;
        }
        
        // February handling
        if (month == 2) {
            bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            int maxDay = isLeap ? 29 : 28;
            if (day > maxDay) {
                std::cout << "Error: bad input => " << iter->first << std::endl;
                continue ;
            }
        }
        
        exchange(iter);
    }
}

void BitcoinExchange::exchange(std::map<std::string, float>::iterator input) {
    std::map<std::string, float>::iterator data = _data.find(input->first);

    if (data == _data.end()) {
        data = _data.lower_bound(input->first);
        // lower_bound returns first element >= key, we want <=
        if (data == _data.begin() && data->first > input->first) {
            std::cout << "Error: date too early => " << input->first << std::endl;
            return;
        }
        if (data == _data.end() || data->first > input->first) {
            --data;
        }
    }
    
    std::cout << input->first << " => " << input->second << " = " 
              << (data->second * input->second) << std::endl;
}
