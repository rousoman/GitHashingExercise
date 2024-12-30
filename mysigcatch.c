#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// Signal handler function for SIGINT
void sigint_handler(int sig) {
    printf("\nCaught signal %d (SIGINT). Exiting...\n", sig);
    exit(EXIT_SUCCESS);
}

int main() {
    // Register the signal handler for SIGINT
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        fprintf(stderr, "Error registering signal handler");
        return EXIT_FAILURE;
    }

    // Infinite loop to keep the program running for catching SIGINT signal
    while (1) {
        printf("Press Ctrl+C to trigger SIGINT signal\n");
	sleep(1);  // Sleep for 1 second
    }

    return EXIT_SUCCESS;
}

