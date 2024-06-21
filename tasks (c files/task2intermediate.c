#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

void execute_command(const char *command, const char *args) {
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        execlp(command, command, args, NULL);
        fprintf(stderr, "Error executing command\n");
        exit(EXIT_FAILURE);
    } else { // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

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

        if (strcmp(command, "ls") == 0) {
            execute_command("ls", "-l");
        } else if (strncmp(command, "mkdir ", strlen("mkdir ")) == 0) {
            execute_command(command, NULL);
        } else if (strcmp(command, "uptime") == 0) {
            execute_command("uptime", "-p");
        } else if (strcmp(command, "sl") == 0) {
            execute_command("sl", NULL);
        } else {
            execute_command(command, NULL);
        }
    }

    return 0;
}
