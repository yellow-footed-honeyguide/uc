#include <stdio.h>
#include <stdlib.h>

/* This function calculates the power of a given base raised to a 
   specified exponent. It handles three specific cases:
   1. If the exponent is 0, it returns 1, because any number raised to the 
   power of 0 is 1.
   2. If the exponent is negative, it calculates the positive exponent power 
   and then takes the reciprocal to handle negative powers.
   3. If the exponent is 1, it simply returns the base, as any number 
   raised to the power of 1 is the number itself. For all other positive 
   exponents, it multiplies the base by itself the number of times 
   specified by the exponent, effectively calculating the power. 
   This loop-based approach is necessary to manually compute the power 
   for integer exponents without using built-in functions. */

long double
exponent_calc (long double base, long double exponent)
{
  if (exponent == 0)
    {
      return 1;
    }
  else if (exponent < 0)
    {
      return 1 / exponent_calc (base, -exponent);
    }
  else if (exponent == 1)
    {
      return base;
    }
  else
    {
      long double result = base;
      for (int i = 1; i < exponent; i++)
	{
	  result *= base;
	}
      return result;
    }
}
