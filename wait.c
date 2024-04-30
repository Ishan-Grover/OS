#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    if(fork()==0)
    {
        printf("Hello from Child\n");
    }
    else
    {
        printf("Hello from Parent\n");
        wait(NULL);
        printf("Child has terminated\n");
    }
    printf("Bye\n");
    return 0;
}
