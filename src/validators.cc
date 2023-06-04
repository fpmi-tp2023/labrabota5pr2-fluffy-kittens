#include "../includes/validators.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

namespace kittens {
    bool IsLoginValid(std::string value) {

    }

    bool IsPasswordValid(std::string value) {

    }
    
    bool IsDataValid(const std::string& value) {
        std::tm time = {};
        std::istringstream ss(value);
        ss >> std::get_time(&time, "%d/%m/%Y");
        return !ss.fail() && ss.eof();
    }

} // namespace kittens