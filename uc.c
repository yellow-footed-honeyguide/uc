#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "handle_arguments.h"
#include "conv_str_to_math_res.h"
#include "exponent_mode.h"

long double previous_result = 0.0;

/* Function to handle tab key press and insert previous result. */
int
insert_previous_result (int count, int key)
{
  if (key == '\t')		// Check if the pressed key is the tab key
    {
      char result_str[32];	// Buffer to store the result string
      sprintf (result_str, "%Lf", previous_result);	// Conv prev res to str and store in buff
      rl_insert_text (result_str);	// Insert the result string at the current cursor position
      rl_redisplay ();		// Redisplay the input line with the inserted text
      return 0;			// Return 0 to indicate successful handling of the tab key
    }
  return rl_insert (count, key);	// If not tab key, pass the arguments to the default rl_insert function
}

int
main (int argc, char *argv[])
{
  handle_arguments (argc, argv);
  rl_bind_key ('\t', insert_previous_result);

  char *exp;			// the math expression from the user.

  /* Loop gets multiple user input expressions. */
  while (1)
    {

      exp = readline ("Expression: ");	// prompt the user for input.

      /* Without this, entering EOF (Ctrl+D) won't exit 
         the loop gracefully. */
      if (exp == NULL)
	{
	  break;
	}

      add_history (exp);	// access prev  expressions using the up/down keys

      switch (exp[0])
	{
	case 'q':
	  free (exp);
	  exit (0);
	case 'e':
	  {
	    long double base, exponent;
	    printf ("Enter base: ");
	    scanf ("%Lf", &base);
	    printf ("Enter exponent: ");
	    scanf ("%Lf", &exponent);
	    long double result = exponent_calc (base, exponent);
	    printf ("Result: %.0Lf\n", result);
	    break;
	  }
	default:
	  {
	    long double result = conv_str_to_math_res (exp);
	    previous_result = result;	// Store the result for later use
	    char *formatted_result = add_spaces_to_triples (result);
	    printf ("Result: %s\n", formatted_result);
	    free (exp);
	    break;
	  }
	}
    }

  return 0;
}
