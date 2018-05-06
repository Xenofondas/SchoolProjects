#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include "display.h"
#include <sys/ipc.h>
#include <fcntl.h>
#include <sys/sem.h> 

#define PERMISSIONS 0600 //Set permissions to 0600

int main()
{
  
  int i,my_sem;
   
    struct sembuf up = {0, 1, 0}; // set to free resource 
    struct sembuf down = {0, -1, 0}; // set to allocate resource 
  

    my_sem = semget(IPC_PRIVATE, 1, IPC_CREAT |PERMISSIONS); /* create semaphore */    
    if(my_sem==-1){
        printf("Error while creating semaphore\n");
        return 1;

    }                    

      semctl(my_sem, 0, SETVAL,0); //Edw arxikh timh tou semaphore einai 0
                                 //gia mhxansmo sygxronismou diergasiwn

  if (fork())
  {
    for (i=0;i<10;i++){
      
      display("ab");
      semop(my_sem, &up, 1);// Molis emfanistei to 'ab' h diergasia ginete ginete trigger gia th deyterh diergasia
      semctl(my_sem, 0, SETVAL,0);//kai sth synexeia h sygkekrimenh diergasia 
      semop(my_sem, &down, 1);    //ginete blocked



      
    }

    /***** Destroy semaphore*******/
    semctl(my_sem, 0, IPC_RMID);       

    wait(NULL);
  }
  else
  {
    for (i=0;i<10;i++){

      
      
      semop(my_sem, &down, 1);// Arxika to child einai blocked 
      display("cd\n");
      semop(my_sem, &up, 1);//Ginete trigger h parent kai h diadikasia epanalambanete
     
    
    }
  }

  return 0;
}
