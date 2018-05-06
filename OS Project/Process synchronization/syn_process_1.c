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
    	struct sembuf up = {0, 1, 0}; /* set to free resource */
    	struct sembuf down = {0, -1, 0}; /* set to allocate resource */
    	
  	
      /***********Create Semaphore***********/
  	  my_sem = semget(IPC_PRIVATE, 1, IPC_CREAT |PERMISSIONS); /* create semaphore */
      if(my_sem==-1){
        printf("Error while creating semaphore\n");
        return 1;

      }
    	semctl(my_sem, 0, SETVAL,1);// Edw thetw arxikh timh 1 sto semaphore 
    	                            // xrisimopoiontas to mhxanismo mutual exclusion(amoibeo apolklismo)
    	
  	
  	

  if (fork()){ //parent 			
  	
    for (i=0;i<10;i++){	
    	
    		semop(my_sem, &down, 1); //Ayto to tmhma kwdika tha ektelestei apokleistika 
    		display("Hello world\n"); // apo mia diergasia kathe fora   	
		  	semop(my_sem, &up, 1);    	
    }	
	    
  	/***** Destroy semaphore*******/
  	semctl(my_sem, 0, IPC_RMID);           

    wait(NULL);

  }
  else //child
  {
  	

    for (i=0;i<10;i++){
    	
    	semop(my_sem, &down, 1);
    	display("Kalimera kosme\n");
    	semop(my_sem, &up, 1);
    	   	
  	}   		
    
  }  
 
  return 0;
}
