#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void print_version() {
    printf("1.6.0\n");
}


void print_help() {
    printf("Usage: uc [OPTIONS]\n");
    printf("\n");
    printf("A command-line calculator that evaluates mathematical expressions.\n");
    printf("\n");
    printf("Options:\n");
    printf("  -v, --version    Print the version information and exit.\n");
    printf("  -h, --help       Print this help message and exit.\n");
    printf("\n");
    printf("Examples:\n");
    printf("  > 20 000 + 5\n");
    printf("  20 005\n");
    printf("\n");
    printf("  > 5000000 * 43 434\n");
    printf("  21 715 000 000.0000\n");
    printf("\n");
    printf("  > 800 000 / 7\n");
    printf("  114 285.7143\n");
    printf("\n");
    printf("  > e\n");
    printf("  Enter Base: 2\n");
    printf("  Enter Exponent: 8\n");
    printf("  256\n");
    printf("\n");
    printf("  > q\n");
    printf("  exit\n");

}

void handle_arguments(int argc, char *argv[]) {
    // If removed, the function will not take command-line arguments, and the program will not be able to handle options.

    int opt;
    // If removed, there will be no variable to store the current option being processed, and the program will not compile.

    struct option long_options[] = {
        {"version", no_argument, 0, 'v'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };
    // If removed, the program will not define the structure for long options, and the getopt_long function will not work correctly.

    while ((opt = getopt_long(argc, argv, "vh", long_options, NULL)) != -1) {
        // If removed, the program will not parse the command-line options and will not handle them accordingly.

        switch (opt) {
            // If removed, the program will not have a way to determine which option was provided and will not take the appropriate action.

            case 'v':
                print_version();
                exit(0);
                // If removed, the program will not print the version information and exit when the -v or --version option is provided.

            case 'h':
                print_help();
                exit(0);
                // If removed, the program will not print the help information and exit when the -h or --help option is provided.

            default:
                printf("Use uc --help\n");
                exit(1);
                // If removed, the program will not handle unknown options and will not provide a helpful message to the user.
        }
    }
}
