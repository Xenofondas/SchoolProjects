#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>





int main(){

	printf("***********************|Shell-1|**********************\n" );

	char command[300];

		
		for(;;){
		//while(strcmp(command,"exit")!=0){
					
					printf("$");
					scanf (" %[^\n]%*c", command);

					if(strcmp(command,"exit")==0) {
					   break;
					};
			
			
			

			pid_t process;
			process = fork();

			char *args1[]={command, 0 };

	            //fork error
	            if (process == -1){ // Error wlile creating process

	               perror("Failed to fork..");
	               //exit(0);
	               
	            }else if(process==0){ // Child process executes here
	            	
	            	
	            //	printf("command=%s\n",args1[1] );
	            	
	            	if(execvp(args1[0],args1)==-1){  
	            		perror("Error while executing command...\n");
	            		break;
	            			            	}

	            }else if(process>0){  // Parent process executes here
	            	//wait for child to end
	            	wait(NULL);
	            	//kill(process, SIGTERM);
	            	
	            }

 		}

//printf("Returned OK!\n");
	return 0;
}