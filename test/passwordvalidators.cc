#include <gtest/gtest.h>
#include "../includes/validators.h"

TEST(PasswordValidation, SimpleString1) {
    EXPECT_EQ(kittens::IsPasswordValid("strongpassword"), true);
}

TEST(PasswordValidation, SimpleString2) {
    EXPECT_EQ(kittens::IsPasswordValid("Qwerty123456"), true);
}

TEST(PasswordValidation, SimpleString3) {
    EXPECT_EQ(kittens::IsPasswordValid("yoooooho"), true);
}


TEST(PasswordValidation, SimpleString4) {
    EXPECT_EQ(kittens::IsPasswordValid("sdfghjklq123"), true);
}


TEST(PasswordValidation, SimpleString5) {
    EXPECT_EQ(kittens::IsPasswordValid("fghjkoiuytews"), true);
}