#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>



/********************PARSER*********************/
void  parse(char *command, char **argv)
{
     char *par;
     int i=0;
     int argn=0;
     //printf("command given is: %s\n", command);
     
     par = strtok (command," "); //Afairw ta kena 

     while(par!= NULL){	

		argv[i]=strdup(par); // kai kathe token pou prokyptei to apothikew sto argv
		//printf("%s\n",par );
		par = strtok(NULL, " ");		
		i++;
		argn++;
	}


	
		for (i = argn; i < 10; ++i){	 //Kanw null ta ypoloipa stoixia tou argv												  
		argv[i]=NULL;					 // giati to array pou prepei na perasw sthn execvp
									 	 //prepei na einai null terminated
		
		}	

		
//	printf("------End of parse----------.\n");
	
}



int main(){

	printf("-----------------Shell----------------\n" );

	char command[300];
	

   		char*  argv[10];
				
		for(;;){

				printf("$");

				scanf (" %[^\n]%*c", command);
				//printf("DAMO==> %s\n",command );
				if(strcmp(command,"exit")==0) {
					   break;
					};
				
				parse(command,argv); //Kanw parse to command poy dothike 

				pid_t process;
				process = fork(); //Ftiaxnw nea diergasia
				

		            //fork error
		            if (process == -1){ // Error wlile creating process

		               perror("Failed to fork..");
		         		               
		            }else if(process==0){ // Child process executes here
		    
		            	if(execvp(argv[0],argv)==-1){
		            		perror("Error while executing command...\n");
		            		break;
		            	}		            	
		            	
		            }else if(process>0){  // Parent process executes here
		            	//wait for child to end
		            	wait(NULL);

		            	

		            }

		           
 		}
            
	return 0;
}