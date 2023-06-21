#ifndef INCLUDES_VALIDATORS_H_
#define INCLUDES_VALIDATORS_H_
#include "./types.h"

namespace kittens {
    bool IsLoginValid(const string& value);
    bool IsPasswordValid(const string& value);
    bool IsDataValid(const string& value);
}  // namespace kittens

#endif /*INCLUDES_VALIDATORS_H_ */
