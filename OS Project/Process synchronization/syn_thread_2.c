#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "display.h"

#define num_threads 2 //aritmos nhmatwn
#define FALSE 0
#define TRUE 1

pthread_t tid[2];
pthread_mutex_t mutex;
pthread_cond_t cond_var;
int predicate = FALSE; //Global "boolean" variable


void* printMessage(void *arg)
{
    int i;
    pthread_t id = pthread_self();//To id pernei thn timh tou kaloumenou thread

    if(pthread_equal(id,tid[0])) //1o thread 
    {
        for(i=0; i<10; i++){
            //Critical Region Start
            pthread_mutex_lock(&mutex);

            if(predicate==TRUE){ // Otan to predicate einai TRUE to sygkekrimeno nhma tha ginei blocked
                pthread_cond_wait (&cond_var,&mutex);
            }
            
                display("ab");

            predicate = TRUE;// Edw h predicate ginnete TRUE gia na ginei block to nhma
            pthread_cond_signal(&cond_var);//Ginete trigger sto 2o nhma afou emfanistei to ab
            
            pthread_mutex_unlock(&mutex);

            //Critical Region End
        }
    }
    else//2o thread
    {
        for(i=0; i<10; i++){
            //Critical Region Start
            pthread_mutex_lock(&mutex);

            if(predicate==FALSE){// Arxika auto to nhma einai blocked , mexri na emfanistei to ab
                pthread_cond_wait (&cond_var,&mutex);// kai  na ginei to predicate TRUE opote tha sinexeisei 
            }


                display("cd\n");


            predicate = FALSE;
            pthread_cond_signal(&cond_var);//Afou emfanistei to ab ginete trigger to 1o Nhma

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

        printf("\n mutex init failed\n");
        return 1;
    }

    //Initialize condition variable
    if(pthread_cond_init(&cond_var, NULL)!= 0){

        printf("\n mutex init failed\n");
        return 1;
    }

    //****************CREATE THREADS*************//
    for(i=0; i<num_threads; i++)
    {
        err = pthread_create(&(tid[i]), NULL, &printMessage, NULL);
        if (err != 0){
            printf("Can't create thread\n");
            return 1;

        }        
    }

    //****************WAIT THREADS*************//
        for(i=0; i<num_threads; i++){
            pthread_join( tid[i], NULL);
        }
        

        

        pthread_mutex_destroy(&mutex);// Destroy mutex

    return 0;
}