#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void print_version() {
    printf("1.4.0\n");
}

void print_help() {
    printf("Example usage:\n");
    printf("$ uc\n");
    printf("> 20 000 + 5\n");
    printf("20 005\n");
    printf("> 5000000 * 43434\n");
    printf("21 715 000 000.0000\n");
    printf("> 800 000 / 7\n");
    printf("114 285.7143\n");
    printf("> q (for quit)\n");
    printf("-v --version\n");
    printf("-h --help\n");
}

void handle_arguments(int argc, char *argv[]) {
    int opt;
    struct option long_options[] = {
        {"version", no_argument, 0, 'v'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "vh", long_options, NULL)) != -1) {
        switch (opt) {
            case 'v':
                print_version();
                exit(0);
            case 'h':
                print_help();
                exit(0);
            default:
                fprintf(stderr, "Invalid option: %c\n", optopt);
                print_help();
                exit(1);
        }
    }
}
