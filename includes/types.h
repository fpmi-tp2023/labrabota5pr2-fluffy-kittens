#ifndef INCLUDES_TYPES_H_
#define INCLUDES_TYPES_H_

#include <functional>
#include <iostream>
#include <memory>
#include <stack>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <regex>
#include <numeric>
#include <math.h>
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

namespace kittens {
using std::cin;
using std::cout;
using std::endl;
using std::function;
using std::make_shared;
using std::make_unique;
using std::shared_ptr;
using std::stack;
using std::string;
using std::string_view;
using std::unique_ptr;
using std::vector;
using std::regex;
using std::regex_match;
using std::tm;
using std::istringstream;
using std::get_time;
using std::accumulate;
using std::floor;
using std::min;
using std::to_string;
using std::cerr;
using std::stoi;
}  // namespace kittens

#endif /* INCLUDES_TYPES_H_ */
