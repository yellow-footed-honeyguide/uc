#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void
print_version ()
{
  printf ("%s\n", UC_VERSION);
}

void
print_help ()
{
  printf ("Usage: uc [OPTIONS]\n");
  printf ("\n");
  printf
    ("A command-line calculator that evaluates mathematical expressions.\n");
  printf ("\n");
  printf ("Options:\n");
  printf ("  -v, --version    Print the version information and exit.\n");
  printf ("  -h, --help       Print this help message and exit.\n");
  printf ("\n");
  printf ("Commands:\n");
  printf ("  > tab (Add to Expression field previous result)\n");
  printf ("\n");
  printf ("  > e   (Switch to Exponent calculation mode)\n");
  printf ("  Enter Base: 2\n");
  printf ("  Enter Exponent: 8\n");
  printf ("  256\n");
  printf ("\n");
  printf ("  > q   (Exit)\n");
  printf ("\n");
  printf ("Examples:\n");
  printf ("  > 20 000 + 5\n");
  printf ("  20 005\n");
  printf ("\n");
  printf ("  > 5000000 * 43 434\n");
  printf ("  21 715 000 000.0000\n");
  printf ("\n");
  printf ("  > 800 000 / 7\n");
  printf ("  114 285.7143\n");
  printf ("\n");
}

void
handle_arguments (int argc, char *argv[])
{

  /* Current option being processed. */
  int opt;

  /* Define the structure for long options. */
  struct option long_options[] = {
    {"version", no_argument, 0, 'v'},
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0}
  };


  /* Parse the command-line options and will not handle them accordingly. */
  while ((opt = getopt_long (argc, argv, "vh", long_options, NULL)) != -1)
    {
      switch (opt)
	{
	  /* Print the --version information. */
	case 'v':
	  print_version ();
	  exit (0);

	  /* Print the  --help information. */
	case 'h':
	  print_help ();
	  exit (0);

	  /* Handle unknown options, provide a help message. */
	default:
	  printf ("Use uc --help\n");
	  exit (1);
	}
    }
}
