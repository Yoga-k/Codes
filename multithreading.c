/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* myThreadFun(void *argv)
{
    for(int i = 0; i < 50 ; i++)
    {
        printf("Fizz\n"); 
    }

    return NULL;
}

void* myThreadFun2(void *argv)
{
    for(int i = 0; i < 50 ; i++)
    {
        printf("Buzz\n"); 
    }
    return NULL;
}

int main()
{
    pthread_t thread_id;
    printf("Before thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_create(&thread_id, NULL, myThreadFun2, NULL);
    pthread_join(thread_id, NULL);
    printf("After thread");
    return 0;
}