#include "../includes/validators.h"
#include "./types.h"

namespace kittens {
    bool IsLoginValid(const string& value) {
        if (value.length() > 30) {
            return false;
        }

        regex regex("[A-Za-z0-9]+");

        return regex_match(value, regex);
    }

    bool IsPasswordValid(const string& value) {
        if (value.length() > 30 || value.length() < 8) {
            return false;
        }

        regex regex("[A-Za-z0-9]+");

        return regex_match(value, regex);
    }
    
    bool IsDataValid(const string& value) {
        tm time = {};
        istringstream ss(value);
        ss >> get_time(&time, "%d/%m/%Y");
        return !ss.fail() && ss.eof();
    }

} // namespace kittens