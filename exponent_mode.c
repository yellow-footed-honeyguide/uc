#include <stdio.h>
#include <stdlib.h>

long double exponent_calc(long double base, long double exponent) {
    if (exponent == 0) {
        return 1;
    } else if (exponent < 0) {
        return 1 / exponent_calc(base, -exponent);
    } else if (exponent == 1) {
        return base;
    } else {
        long double result = base;
        for (int i = 1; i < exponent; i++) {
            result *= base;
        }
        return result;
    }
}
