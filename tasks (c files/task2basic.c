#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

void execute_command(const char *command) {
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { 
        execlp(command, command, NULL);
        fprintf(stderr, "Error executing command\n");
        exit(EXIT_FAILURE);
    } else { 
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
            execute_command("ls");
        } else if (strncmp(command, "mkdir ", strlen("mkdir ")) == 0) {
            execute_command(command);
        } else if (strcmp(command, "uptime") == 0) {
            execute_command("uptime");
        } else if (strcmp(command, "sl") == 0) {
            execute_command("sl");
        } else {
            execute_command(command);
        }
    }

    return 0;
}
