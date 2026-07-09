#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void loadData();
        void processInput(const char* file);
        void validInput(std::string date, float value);
        void exchange(std::string date, float value);
};

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& exchange);