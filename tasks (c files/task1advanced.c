#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>

#define MAX_COMMAND_LENGTH 1024
#define PROMPT_FORMAT "%s@%s:%s$ "

void display_prompt() {
    char hostname[HOST_NAME_MAX];
    char username[LOGIN_NAME_MAX];
    char cwd[PATH_MAX];

    gethostname(hostname, HOST_NAME_MAX);
    getlogin_r(username, LOGIN_NAME_MAX);
    getcwd(cwd, PATH_MAX);

    printf(PROMPT_FORMAT, hostname, username, cwd);
    fflush(stdout);
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {

        display_prompt();

        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Fork a child process
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
