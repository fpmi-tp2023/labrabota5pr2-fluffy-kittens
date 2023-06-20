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

