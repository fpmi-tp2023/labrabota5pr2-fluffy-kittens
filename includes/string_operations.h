#ifndef INCLUDES_STRING_OPERATIONS_H_
#define INCLUDES_STRING_OPERATIONS_H_

#include "./types.h"

namespace kittens {
namespace utils {
vector<string> SplitString(string s);
vector<string> SplitLine(string line, int line_width);
}
}  // namespace kittens

#endif /* INCLUDES_STRING_OPERATIONS_H_ */
