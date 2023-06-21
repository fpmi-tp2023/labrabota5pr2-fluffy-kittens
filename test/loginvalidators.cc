#include <gtest/gtest.h>
#include "../includes/validators.h"

TEST(LoginValidation, SimpleString1) {
    EXPECT_EQ(kittens::IsLoginValid("artyomshpakovski"), true);
}

TEST(LoginValidation, SimpleString2) {
    EXPECT_EQ(kittens::IsLoginValid("petrik33"), true);
}

TEST(LoginValidation, SimpleString3) {
    EXPECT_EQ(kittens::IsLoginValid("LisaShymkovich"), true);
}

TEST(LoginValidation, SimpleString4) {
    EXPECT_EQ(kittens::IsLoginValid("kiriller_102"), false);
}

TEST(LoginValidation, SimpleString5) {
    EXPECT_EQ(kittens::IsLoginValid("90/01/1999"), false);
}

TEST(LoginValidation, EmptyString) {
    EXPECT_EQ(kittens::IsLoginValid(""), false);
}

TEST(LoginValidation, StringWithSpaces1) {
    EXPECT_EQ(kittens::IsLoginValid(" "), false);
}

TEST(LoginValidation, StringWithSpaces2) {
    EXPECT_EQ(kittens::IsLoginValid("   "), false);
}

TEST(LoginValidation, StringWithSpaces3) {
    EXPECT_EQ(kittens::IsLoginValid(" a "), false);
}

TEST(LoginValidation, StringWithSpaces4) {
    EXPECT_EQ(kittens::IsLoginValid("     1"), false);
}

TEST(LoginValidation, StringWithSpaces5) {
    EXPECT_EQ(kittens::IsLoginValid(" a a a"), false);
}


