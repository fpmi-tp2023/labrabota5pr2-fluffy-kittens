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

TEST(PasswordValidation, NotEnoghLength1) {
    EXPECT_EQ(kittens::IsPasswordValid("1"), false);
}

TEST(PasswordValidation, NotEnoghLength2) {
    EXPECT_EQ(kittens::IsPasswordValid("sad"), false);
}

TEST(PasswordValidation, NotEnoghLength3) {
    EXPECT_EQ(kittens::IsPasswordValid("asdsd"), false);
}

TEST(PasswordValidation, NotEnoghLength4) {
    EXPECT_EQ(kittens::IsPasswordValid(""), false);
}

TEST(PasswordValidation, NotEnoghLength5) {
    EXPECT_EQ(kittens::IsPasswordValid("123"), false);
}

TEST(PasswordValidation, TooBigLength1) {
    EXPECT_EQ(kittens::IsPasswordValid("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"), false);
}

TEST(PasswordValidation, TooBigLength2) {
    EXPECT_EQ(kittens::IsPasswordValid("1234567890iuygtfdsazxcvbnhjuytrewq2345"), false);
}

TEST(PasswordValidation, TooBigLength3) {
    EXPECT_EQ(kittens::IsPasswordValid("asdfghjkliuytrew234rtfdsaASDFGHFDWER434567"), false);
}

TEST(PasswordValidation, TooBigLength4) {
    EXPECT_EQ(kittens::IsPasswordValid("12345678909876543212345678908765432123456789098765432"), false);
}

TEST(PasswordValidation, TooBigLength5) {
    EXPECT_EQ(kittens::IsPasswordValid("sdfghjuytrewsaxcvbhjytrewsxcvbnhjuytresxcvbnhjuytredcvbhytred"), false);
}

TEST(PasswordValidation, Spaces1) {
    EXPECT_EQ(kittens::IsPasswordValid("          "), false);
}

TEST(PasswordValidation, Spaces2) {
    EXPECT_EQ(kittens::IsPasswordValid("asdsa 123123"), false);
}

TEST(PasswordValidation, Spaces3) {
    EXPECT_EQ(kittens::IsPasswordValid("1232132211 "), false);
}

TEST(PasswordValidation, Spaces4) {
    EXPECT_EQ(kittens::IsPasswordValid("616326132613261 32 "), false);
}

TEST(PasswordValidation, Spaces5) {
    EXPECT_EQ(kittens::IsPasswordValid("23456hvde 3456789oijhgfde3456yh"), false);
}

TEST(PasswordValidation, EmptyString) {
    EXPECT_EQ(kittens::IsPasswordValid(""), false);
}