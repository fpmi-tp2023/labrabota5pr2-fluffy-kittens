#include <gtest/gtest.h>
#include "../includes/validators.h"

TEST(DateValidation, SimpleData1) {
    // 12/06/2010
    EXPECT_EQ(kittens::IsDataValid("12/06/2010"), true);
}

TEST(DateValidation, SimpleData2) {
    // 20/01/1999
    EXPECT_EQ(kittens::IsDataValid("20/01/1999"), true);
}

TEST(DateValidation, SimpleData3) {
    // 12/12/1900
    EXPECT_EQ(kittens::IsDataValid("12/12/1900"), true);
}

TEST(DateValidation, SimpleData4) {
    // -12/03/2010
    EXPECT_EQ(kittens::IsDataValid("-12/03/2010"), false);
}

TEST(DateValidation, SimpleData5) {
    // 90/01/1999
    EXPECT_EQ(kittens::IsDataValid("90/01/1999"), false);
}

TEST(DateValidation, EmptyString) {
    EXPECT_EQ(kittens::IsDataValid(""), false);
}
