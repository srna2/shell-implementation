#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

void execute_command(const char *command, const char *args, int pipe_fd[]) {
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        if (pipe_fd != NULL) {
            close(pipe_fd[0]);
            dup2(pipe_fd[1], STDOUT_FILENO);
            close(pipe_fd[1]);
        }

        execlp(command, command, args, NULL);
        fprintf(stderr, "Error executing command\n");
        exit(EXIT_FAILURE);
    } else { // Parent process
        if (pipe_fd != NULL) {
            close(pipe_fd[1]);
        }

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

        char *pipe_symbol = strchr(command, '|');
        if (pipe_symbol != NULL) {
            *pipe_symbol = '\0';
            char *command1 = command;
            char *command2 = pipe_symbol + 1;

            int pipe_fd[2];
            if (pipe(pipe_fd) == -1) {
                perror("Pipe failed");
                exit(EXIT_FAILURE);
            }

            execute_command(command1, NULL, pipe_fd);
            execute_command(command2, NULL, NULL);

            close(pipe_fd[0]);
            close(pipe_fd[1]);
        } else {
            if (strcmp(command, "ls") == 0) {
                execute_command("ls", "-l", NULL);
            } else if (strncmp(command, "mkdir ", strlen("mkdir ")) == 0) {
                execute_command(command, NULL, NULL);
            } else if (strcmp(command, "uptime") == 0) {
                execute_command("uptime", "-p", NULL);
            } else if (strcmp(command, "sl") == 0) {
                execute_command("sl", NULL, NULL);
            } else {
                execute_command(command, NULL, NULL);
            }
        }
    }

    return 0;
}
