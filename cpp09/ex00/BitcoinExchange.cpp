#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data() {}

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
    loadData();
    std::string date;
    float value = 0;
    std::ifstream infile(file);
    if (!infile.is_open())
    throw std::runtime_error("could not open file");
std::string line;
if (!std::getline(infile, line))
throw std::runtime_error("could not read file");
while (std::getline(infile, line))
{
        bool valid = true;
        size_t commaPos = line.find(' ');
        if (commaPos != std::string::npos)
        {
            date = line.substr(0, commaPos);
            if (line[commaPos + 1] != '|' || line[commaPos + 2] != ' '
            || line[commaPos + 3] == '\0')
            {
                std::cout << "Error: bad input => " << date << std::endl;
                continue ;
            }
            for (size_t i = commaPos + 3; i < line.size(); i++)
            {
                if (!isdigit(line[i]) && line[i] != '.')
                    valid = false;
            }
            if (!valid) {
                std::cout << "Error: bad input => " << date << std::endl;
                continue ;}
            value = std::atof(line.substr(commaPos + 3).c_str());
        }
        else
        {
            std::cout << "Error: bad input => Unexpected end of line." << std::endl;
            continue ;
        }
        validInput(date, value);
    }
    infile.close();
}

void BitcoinExchange::validInput(std::string date, float value) {
    int year = 0, month = 0, day = 0;

        // Check basic format
        if (date.length() != 10 
            || date[4] != '-' || date[7] != '-') {
            std::cout << "Error: bad input => " << date << std::endl;
            return  ;
        }
        
        // Check value range
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            return  ;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            return  ;
        }
        
        // Check all characters are digits or dashes in correct positions
        bool valid = true;
        for (size_t i = 0; i < date.length(); i++) {
            if (i == 4 || i == 7) {
                if (date[i] != '-') {
                    valid = false;
                    break ;
                }
            } else if (!std::isdigit(date[i])) {
                valid = false;
                break ;
            }
        }
        if (!valid) {
            std::cout << "Error: bad input => " << date << std::endl;
            return  ;
        }
        
        year = std::atoi(date.substr(0, 4).c_str());
        month = std::atoi(date.substr(5, 2).c_str());
        day = std::atoi(date.substr(8, 2).c_str());
        
        // Basic date validation
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            std::cout << "Error: bad input => " << date << std::endl;
            return  ;
        }
        
        // Month-specific day limits
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
            std::cout << "Error: bad input => " << date << std::endl;
            return  ;
        }
        
        // February handling
        if (month == 2) {
            bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            int maxDay = isLeap ? 29 : 28;
            if (day > maxDay) {
                std::cout << "Error: bad input => " << date << std::endl;
                return  ;
            }
        }
        exchange(date, value);
}

void BitcoinExchange::exchange(std::string date, float value) {

    std::map<std::string, float>::iterator data = _data.find(date);

    if (data == _data.end()) {
        data = _data.lower_bound(date);
        // lower_bound returns first element >= key, we want <=
        if (data == _data.begin() && data->first > date) {
            std::cout << "Error: date too early => " << date << std::endl;
            return ;
        }
        if (data == _data.end() || data->first > date) {
            --data;
        }
    }
    
    std::cout << date << " => " << value << " = " 
              << (data->second * value) << std::endl;
}
