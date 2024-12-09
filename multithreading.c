/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
sem_t mutex;
int turn = 0;

void* printFizz(void *argv)
{
    sem_wait(&mutex);
    for(int i = 0; i < 50 ; i++)
    {
        while(1)
        {
           if(turn == 0)
           {
            printf("Fizz\n");
            turn = 1;
            sem_post(&mutex);
            break;
           }
        }
       usleep(1);
    }
    sem_post(&mutex);
    return NULL;
}

void* printBuzz(void *argv)
{
    sem_wait(&mutex);
    for(int i = 0; i < 50 ; i++)
    {
        while(1)
        {
           if(turn == 1)
           {
            printf("Buzz\n");
            turn = 0;
            sem_post(&mutex);
            break;
           }
            sem_post(&mutex);
        }
        usleep(1);

    }

    return NULL;
}

int main()
{
    sem_init(&mutex, 0, 1);
    pthread_t fizzthread, buzzthread;
    printf("Before thread\n");
    pthread_create(&fizzthread, NULL, printFizz, NULL);
    pthread_create(&buzzthread, NULL, printBuzz, NULL);
    pthread_join(fizzthread, NULL);
    pthread_join(buzzthread, NULL);
    printf("After thread");
    sem_destroy(&mutex);
    return 0;
}