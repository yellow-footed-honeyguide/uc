#ifndef CONV_STR_TO_MATH_RES_H
#define CONV_STR_TO_MATH_RES_H

#include <stdlib.h>

long double evaluateExpression(const char *expr);
long double parseMathExpression(const char *expr);
char *formatResult(long double result);

#endif // CONV_STR_TO_MATH_RES_H
