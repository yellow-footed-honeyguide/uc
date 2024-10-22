/**
 * @file test_uc.c
 * @brief Unit tests for Unix Calculator (uc) using Unity framework
 */

#include "unity.h"
#include "conv_str_to_math_res.h"
#include "exponent_mode.h"
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

/* Basic Arithmetic Tests */

void test_division_with_simple_numbers(void) {
    TEST_MESSAGE("Testing division with simple numbers");
    long double result = conv_str_to_math_res("10000/3");
    char* formatted = add_spaces_to_triples(result);
    TEST_ASSERT_EQUAL_STRING("3 333.3333", formatted);
}

void test_addition_with_large_numbers(void) {
    TEST_MESSAGE("Testing addition with large numbers");
    long double result = conv_str_to_math_res("1000+500000");
    char* formatted = add_spaces_to_triples(result);
    TEST_ASSERT_EQUAL_STRING("501 000", formatted);
}

void test_multiplication_with_decimals(void) {
    TEST_MESSAGE("Testing multiplication with decimals");
    long double result = conv_str_to_math_res("3.14*2");
    char* formatted = add_spaces_to_triples(result);
    TEST_ASSERT_EQUAL_STRING("6.2800", formatted);
}

void test_complex_expression(void) {
    TEST_MESSAGE("Testing complex expression");
    long double result = conv_str_to_math_res("1000000/2*3+1000");
    char* formatted = add_spaces_to_triples(result);
    TEST_ASSERT_EQUAL_STRING("1 501 000", formatted);
}


int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_division_with_simple_numbers);
    RUN_TEST(test_addition_with_large_numbers);
    RUN_TEST(test_multiplication_with_decimals);
    RUN_TEST(test_complex_expression);

    return UNITY_END();
}
