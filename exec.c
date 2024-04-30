#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
 printf("I am exec and my pid is %d", getpid());
 char* arg[]={"./outputfile",NULL};
 execv(arg[0],arg);
 printf("I will not print");
 return 0;
}