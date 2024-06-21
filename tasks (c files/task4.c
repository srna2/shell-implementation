#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

void print_prompt() {
    printf("\033[0;34m");
    printf("OurShellIsTheBest:)$ ");
    printf("\033[0m"); 
}

int main() {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        print_prompt();
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';


        if (strcmp(input, "exit") == 0) {
            printf("Exiting shell.\n");
            break;
        }


    }
        return 0;
}
