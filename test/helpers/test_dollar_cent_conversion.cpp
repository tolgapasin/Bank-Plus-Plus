#include <gtest/gtest.h>
#include "../../src/helpers/dollar_cent_conversion_helper.h"

TEST(DollarCentConversionTests, CentsToDollars) {
    long long dollars = DollarCentConversionHelper::CentsToDollars(500);
    EXPECT_EQ(5, dollars);
}

TEST(DollarCentConversionTests, DollarsToCents) {
    long long cents = DollarCentConversionHelper::DollarsToCents(5);
    EXPECT_EQ(500, cents);
}