#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "display.h"

#define num_threads 2 //aritmos nhmatwn

pthread_t tid[2];
pthread_mutex_t mutex;



void* printMessage(void *arg)
{
    unsigned long i = 0;
    pthread_t id = pthread_self();//To id pernei thn timh tou kaloumenou thread

    if(pthread_equal(id,tid[0])) //1o thread 
    {
        for(i=0; i<10; i++){
            //Critical Region Start
            pthread_mutex_lock(&mutex);
            
            display("Hello world\n");// Auto to block ekteleite apoklistika apo 1 nhma kathe fora
            
            pthread_mutex_unlock(&mutex);

            //Critical Region End
        }
    }
    else//2o thread
    {
        for(i=0; i<10; i++){
            //Critical Region Start
            pthread_mutex_lock(&mutex);

            display("Kalimera kosme\n");

            pthread_mutex_unlock(&mutex);
            //Critical Region End
        }
    }

   

    return NULL;
}

int main(void)
{
    int i = 0;
    int err;


    //Initialize mutex
    if(pthread_mutex_init(&mutex, NULL) != 0){
            //printf("\n mutex init failed\n");
            return 1;
    }



    //****************CREATE THREADS*************//
    for(i=0; i<num_threads; i++)
    {
        err = pthread_create(&(tid[i]), NULL, &printMessage, NULL);
        if (err != 0){
            //printf("Can't create thread\n");
            return 1;

        }        
    }

    //****************WAIT THREADS*************//
    for(i=0; i<num_threads; i++){
        pthread_join( tid[i], NULL);
    }

        pthread_mutex_destroy(&mutex);

    return 0;
}