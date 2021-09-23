/*
Student No.: 610001001
Student Name: Yi-Chang Lin
Email: kiraskywing@gmail.com
SE tag: xnxcxtxuxoxsx
Statement: I am fully aware that this program is not supposed to be posted to a public server, such as a public GitHub repository or a public web page.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

char praser(char *input, char *args1[], char *args2[], bool *hasAmp1, bool* hasAmp2);
int argSpliter(char *input, char *args[], bool *hasAmp);
void pipeDealer(char *args1[], char *args2[], bool hasAmp);
void fileDealer(char *args1[], char *args2[], char type);

int main(void) {
    char inputLine[257], *args1[257], *args2[257];

    while (true) {
        putchar('>');
        fgets(inputLine, 257, stdin);
        bool hasAmp1 = false, hasAmp2 = false;
        char divider = praser(inputLine, args1, args2, &hasAmp1, &hasAmp2);

        pid_t pid = fork();
        int status, ret;
        if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            exit(-1);
        }
        else if (pid == 0) {
            switch (divider) {
                case '|':
                    pipeDealer(args1, args2, hasAmp1);
                    break;
                case '<':
                    fileDealer(args1, args2, divider);
                    break;
                case '>':
                    fileDealer(args1, args2, divider);
                    break;
                default:
                    if (execvp(args1[0], args1) < 0) {
                        fprintf(stderr, "Exec failed\n");
                        exit(-1);
                    }
                    break;
            }
            exit(0);
        }
        else {
            if ((!divider && !hasAmp1) || (divider && !hasAmp2)) { ret = waitpid(pid, &status, 0); }
            else { ret = waitpid(pid, &status, WNOHANG); }
            
            if (ret < 0) {
                fprintf(stderr, "Wait error\n");
                exit(-1);
            }

            // if (WIFEXITED(status))
            //     printf("child_pid: %d, normal exit status: %d\n", ret, WEXITSTATUS(status));
            // else if (WIFSIGNALED(status))
            //     printf("child_pid: %d, abnormal signal number: %d\n", ret, WTERMSIG(status));
            // else if (WIFSTOPPED(status))
            //     printf("child_pid: %d, stoped signal number: %d\n", ret, WSTOPSIG(status));
        }
    }

    return 0;
}

char praser(char *input, char *args1[], char *args2[], bool *hasAmp1, bool* hasAmp2) {
    char *cur = input;
    while (*cur && *cur != '|' && *cur != '>' && *cur != '<')
        cur++;
    
    char c = *cur;
    if (*cur) {
        *cur = '\0';
        argSpliter(cur + 1, args2, hasAmp2);
    }
    argSpliter(input, args1, hasAmp1);
    
    return c;
}

int argSpliter(char *input, char *args[], bool *hasAmp) {
    int n_args = 0;
    input = strtok(input, " \n");
    while (input) {
        args[n_args++] = input;
        input = strtok(NULL, " \n");
    }
    if (strcmp(args[n_args - 1], "&") == 0) {
        *hasAmp = true;
        n_args--;
    }
    args[n_args] = NULL;
    
    return n_args;
}

void pipeDealer(char *args1[], char *args2[], bool hasAmp) {
    int fds[2];
    if (pipe(fds) == -1) {
        fprintf(stderr, "Open pipe failed!\n");
        exit(-1);
    }

    pid_t pid = fork();
    int status, ret;
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(-1);
    }
    else if (pid == 0) {
        close(fds[0]);
        dup2(fds[1], STDOUT_FILENO);
        if (execvp(args1[0], args1) < 0) { 
            fprintf(stderr, "Exec failed\n");
            exit(-1); 
        }
        close(fds[1]);
        exit(0);
    }
    else {
        if (!hasAmp) { ret = waitpid(pid, &status, 0); }
        else { ret = waitpid(pid, &status, WNOHANG); }

        if (ret < 0) {
                fprintf(stderr, "Wait error\n");
                exit(-1);
        }

        close(fds[1]);
        dup2(fds[0], STDIN_FILENO);
        if (execvp(args2[0], args2) < 0) {
            fprintf(stderr, "Exec failed\n");
            exit(-1); 
        }
        close(fds[0]);

        // if (WIFEXITED(status))
        //     printf("child_pid: %d, normal exit status: %d\n", ret, WEXITSTATUS(status));
        // else if (WIFSIGNALED(status))
        //     printf("child_pid: %d, abnormal signal number: %d\n", ret, WTERMSIG(status));
        // else if (WIFSTOPPED(status))
        //     printf("child_pid: %d, stoped signal number: %d\n", ret, WSTOPSIG(status));
    }
}

void fileDealer(char *args1[], char *args2[], char type) {
    if (type == '>') {
        int fd = open(args2[0], O_WRONLY | O_CREAT, S_IRWXU | S_IRWXO);
        if (fd == -1) {
            fprintf(stderr, "Open/Create file failed\n");
            exit(-1);
        }
        dup2(fd, STDOUT_FILENO);
        if (execvp(args1[0], args1) < 0) { 
            fprintf(stderr, "Exec failed\n");
            exit(-1); 
        }
        close(fd);
    }
    else {
        int fd = open(args2[0], O_RDONLY | O_CREAT);
        if (fd == -1) {
            fprintf(stderr, "Open file failed\n");
            exit(-1);
        }
        dup2(fd, STDIN_FILENO);
        if (execvp(args1[0], args1) < 0) { 
            fprintf(stderr, "Exec failed\n");
            exit(-1); 
        }
        close(fd);
    }
}