#include "dollar_cent_conversion_helper.h"
#include <cmath>

// These two functions need rounding because when converting dollars to cents and vice versa
// the answer may be something like 32.23 -> 3222.999 and if we dont round we will be off by one cent
double DollarCentConversionHelper::CentsToDollars(long long cents) {
    return static_cast<double>(std::round(cents / 100));
};

long long DollarCentConversionHelper::DollarsToCents(double dollars) {
    return static_cast<long long>(std::round(dollars * 100));
};