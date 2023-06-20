#include "../includes/validators.h"
#include <regex>
#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

namespace kittens {
    bool IsLoginValid(const std::string& value) {
        if (value.length() > 30) {
            return false;
        }

        std::regex regex("[A-Za-z0-9]+");

        return std::regex_match(value, regex);
    }

    bool IsPasswordValid(const std::string& value) {
        if (value.length() > 30 || value.length() < 8) {
            return false;
        }

        std::regex regex("[A-Za-z0-9]+");

        return std::regex_match(value, regex);
    }
    
    bool IsDataValid(const std::string& value) {
        std::tm time = {};
        std::istringstream ss(value);
        ss >> std::get_time(&time, "%d/%m/%Y");
        return !ss.fail() && ss.eof();
    }

} // namespace kittens