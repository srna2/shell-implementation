#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("prompt$ ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0) {
            break;
        }

        pid_t pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            return 1;
        } else if (pid == 0) { // Child process
            execlp(command, command, NULL);

            fprintf(stderr, "Error executing command\n");
            exit(1);
        } else { // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
