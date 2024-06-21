#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = rfork(RFPROC | RFMEM);

    if (pid < 0) {
        perror("rfork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed");
        exit(EXIT_FAILURE);
    } else {
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process terminated abnormally\n");
        }
    }

    return 0;
}
