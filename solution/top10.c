// example of running 'cat top10.c | grep if'
// to compile type 'gcc top10.c -o top10'
// to run type './top10'
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
 int main() {
    int fd[2], status;                                         
    // creating unnamed pipe
    pipe(fd);
    // cloning the parent
    pid_t pid1 = fork();                
               
    if (!pid1) {
        // child this process is going to write to pipe
        // redirecting STDOUT (fd==1) to pipe
        dup2(fd[1], 1);
        // closing both ends of the pipe
        close(fd[0]);
        close(fd[1]);      
        // execute cat
        char* command[3] = {"/bin/cat", "top10.c", NULL};
        execv(command[0], command);
        exit(EXIT_FAILURE);
    } else if (pid1 == -1) {                                   
        // fork() returns -1 upon error
        fprintf(stderr, "Can't fork, exiting...\n");           
        exit(EXIT_FAILURE);
    }                                                          
    pid_t pid2 = fork();                                       
    if (!pid2) {
        // child process is going to read from pipe
        // redirecting STDIN (fd==0) to pipe                                               
        dup2(fd[0], 0);
        close(fd[0]);
        close(fd[1]); 
        // execute grep
        char* command[4] = {"/bin/grep", "--color=auto", "if", NULL};
        execv(command[0], command);
        exit(EXIT_FAILURE);                            
    } else if (pid2 == -1) {             
        fprintf(stderr, "Can't fork, exiting...\n");
        exit(EXIT_FAILURE);
    }
    close(fd[0]);
    close(fd[1]);
    // wait for child process to exit
    waitpid(pid1, NULL, 0);                                 
    waitpid(pid2, &status, 0);                       
    // exit with the exit status of grep
    exit(status);
    int A[2]; 
    pipe(A);
    pid_t pid1 = fork(); 
    if (!pid1) {
        dup2(A[1], 1);
        close(A[0]);
        close(A[1]);
        execlp("cut","cut", "-f11", "-d ", "log.txt", NULL);
        exit(EXIT_FAILURE);
    }
    
    int B[2]; 
    pipe(B);
    pid_t pid2 = fork();
    if (!pid2) { 
        dup2(A[0], 0);
        close(A[0]);
        close(A[1]);
        
        dup2(B[1], 1);
        close(B[0]);
        close(B[1]);
        
        execlp("grep","grep", "-v", "-", NULL);
        exit(EXIT_FAILURE);
    }
    
    close(A[0]);
    close(A[1]);
    
    int C[2]; 
    pipe(C);
    
    pid_t pid3 = fork();
    if (!pid3) { 
        dup2(B[0], 0);
        close(B[0]);
        close(B[1]);
        
        dup2(C[1], 1);
        close(C[0]);
        close(C[1]);
        
        execlp("sort","sort", NULL);
        exit(EXIT_FAILURE);
    }
    
    close(B[0]);
    close(B[1]);
    
    
    int D[2]; // pipe D
    pipe(D);
    
    pid_t pid4 = fork();
    if (!pid4) {
        dup2(C[0], 0);
        close(C[0]);
        close(C[1]);
        
        dup2(D[1], 1);
        close(D[0]);
        close(D[1]);
        
        execlp("uniq","uniq", "-c", NULL);
        exit(EXIT_FAILURE);
    }
    
    close(C[0]);
    close(C[1]);
    
    int E[2]; 
    pipe(E);
    
    pid_t pid5 = fork();
    if (!pid5) {
        dup2(D[0], 0);
        close(D[0]);
        close(D[1]);
        
        dup2(E[1], 1);
        close(E[0]);
        close(E[1]);
        
        execlp("sort","sort", "-rn", NULL);
        exit(EXIT_FAILURE);
    }
    
    close(D[0]);
    close(D[1]);
    
    int F[2]; // pipe F
    pipe(F);
    
    pid_t pid6 = fork();
    if (!pid6) { // sort
        dup2(E[0], 0);
        close(E[0]);
        close(E[1]);
        
        dup2(F[1], 1);
        close(F[0]);
        close(F[1]);
        
        execlp("cat","cat", "-n", NULL);
        exit(EXIT_FAILURE);
    }
    
    close(E[0]);
    close(E[1]);
    
    int G[2]; 
    pipe(G);
    
    pid_t pid7 = fork();
    if (!pid7) { 
        dup2(F[0], 0);
        close(F[0]);
        close(F[1]);
        
        dup2(G[1], 1);
        close(G[0]);
        close(G[1]);
        
        execlp("awk", "awk", " { print $1 \". \" $3 \" - \" $2 \" - \" int($2/1120*100) \"%\" } ", NULL);
        exit(EXIT_FAILURE);
    }
    
    close(F[0]);
    close(F[1]);
    
    pid_t pid8 = fork();
    if (!pid8) { 
        dup2(G[0], 0);
        close(G[0]);
        close(G[1]);
        execlp("head", "head", "-n", "10", NULL);
        exit(EXIT_FAILURE);
    }
    
   
    close(G[0]);
    close(G[1]);
    waitpid(pid8, 0, 0);
}
