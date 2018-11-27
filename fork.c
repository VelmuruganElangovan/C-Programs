
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

void forkexample() 
{ 

    // child process because return value zero 
    if (fork() == 0)
    { 
	
        printf("Hello from Child!\n");
	printf("My process ID : %d\n\n", getpid());
 
    }
    // parent process because return value non-zero. 
    else
    {

        printf("Hello from Parent!\n"); 
	printf("My process ID : %d\n\n", getpid());

    }
}

 
int main() 
{ 
    forkexample(); 
    return 0; 
} 

