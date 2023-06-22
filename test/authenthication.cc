#include <gtest/gtest.h>
#include "../includes/authenthication.h"

TEST(Authenthication, Authenthication1) {
    auto result = kittens::AuthManager::Authorize("petrik3003", "30032004");
    EXPECT_EQ(result, true) << "Expected result to be equal true but equals" << result;
}

TEST(Authenthication, Authenthication2) {
    auto result = kittens::AuthManager::Authorize("petrik33", "30");
    EXPECT_EQ(result, false) << "Expected result to be equal true but equals" << result;
}

TEST(Authenthication, Authenthication3) {
    auto result = kittens::AuthManager::Authorize("lisashymkovich", "18042003");
    EXPECT_EQ(result, true);
}

TEST(Authenthication, Authenthication4) {
    auto result = kittens::AuthManager::Authorize("lisashymkovich", "123456");
    EXPECT_EQ(result, false);
}

TEST(Authenthication, Authenthication5) {
    auto result = kittens::AuthManager::Authorize("artyomshpakovski", "19082004");
    EXPECT_EQ(result, true);
}

TEST(Authenthication, Authenthication6) {
    auto result = kittens::AuthManager::Authorize("artyomshpakovski", "1908200");
    EXPECT_EQ(result, false);
}

TEST(Authenthication, Authenthication7) {
    auto result = kittens::AuthManager::Authorize("kiriller_102", "0123456");
    EXPECT_EQ(result, false);
}

TEST(Authenthication, Authenthication8) {
    auto result = kittens::AuthManager::Authorize("papavlusha", "abrakadabbra");
    EXPECT_EQ(result, false);
}

TEST(Authenthication, Authenthication9) {
    auto result = kittens::AuthManager::Authorize("petrik3003", "abrakadabbra");
    EXPECT_EQ(result, false);
}

TEST(Authenthication, Authenthication10) {
    auto result = kittens::AuthManager::Authorize("petrik3003", "");
    EXPECT_EQ(result, false);
}

TEST(Authenthication, Authenthication11) {
    auto result = kittens::AuthManager::Authorize("lisashymkovich", "aqwegsfnfjash");
    EXPECT_EQ(result, false);
}

TEST(Authenthication, Authenthication12) {
    auto result = kittens::AuthManager::Authorize("lisashymkovich", "strongpassword");
    EXPECT_EQ(result, false);
}

TEST(Authenthication, Authenthication13) {
    auto result = kittens::AuthManager::Authorize("artyomshpakovski", "superstrongpassword");
    EXPECT_EQ(result, false);
}

TEST(Authenthication, Authenthication14) {
    auto result = kittens::AuthManager::Authorize("artyomshpakovski", "12436y7gfa");
    EXPECT_EQ(result, false);
}









