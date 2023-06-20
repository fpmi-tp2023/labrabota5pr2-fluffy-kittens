#ifndef INCLUDES_VALIDATORS_H_
#define INCLUDES_VALIDATORS_H_

#include <string>

namespace kittens {
    bool IsLoginValid(const std::string& value);
    bool IsPasswordValid(const std::string& value);
    bool IsDataValid(const std::string& value);
}  // namespace kittens

#endif /*INCLUDES_VALIDATORS_H_ */