#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <boost/regex.hpp>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;
        std::map<std::string, float> _input;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void loadData();
        void processInput(const char* file);
        void validInput();
};

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& exchange);