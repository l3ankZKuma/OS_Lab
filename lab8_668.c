#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>
#include<unistd.h>
int notDone = 1; int cnt = 0;
void mySIGhandler(int sig) {
    signal(SIGALRM,SIG_IGN);
    
    notDone = 0;
    
}
int main(void) {
    
    signal(SIGALRM,mySIGhandler);
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child created\n");
        while(1);
        printf("this line should not be shown\n");
        exit(0);
    } else {
        kill(getppid(),SIGALRM);
        while (notDone) cnt++; 
    }
    
    printf("it takes %d\n",cnt);
return 0;
} //main