#include <gtest/gtest.h>
#include "../includes/authenthication.h"

TEST(HashFunction, HashFunc1) {
    auto hash_result = kittens::AuthManager::AuthHash("30032004");
    EXPECT_EQ(hash_result, 396) << "Expected result to be equal 396 but equals " << hash_result;
}

TEST(HashFunction, HashFunc2) {
    auto hash_result = kittens::AuthManager::AuthHash("18042003");
    EXPECT_EQ(hash_result, 402) << "Expected result to be equal 402 but equals " << hash_result;
}

TEST(HashFunction, HashFunc3) {
    auto hash_result = kittens::AuthManager::AuthHash("17082004");
    EXPECT_EQ(hash_result, 406) << "Expected result to be equal 406 but equals " << hash_result;
}