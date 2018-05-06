#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


#define READ_END 0
#define WRITE_END 1

void  parse(char *command, char **argv1,char **argv2) //Edw kanoume parsing sthn entolh pou doyhike
{
	char *commandl[3];
    char *pch;
    int i=0;
    int k=0; //to k einai o metriths twn orismatwn
//    printf("command given is: %s\n", command);

    commandl[0]=NULL;
    commandl[1]=NULL;
    //commandl[1]=NULL;


     pch = strtok (command,"|"); //Ksexorizw thn pipe entolh se 2 ypo entoles
	

	while (pch != NULL)
	{	

		commandl[i]=strdup(pch);
		pch = strtok (NULL, "|");
		if(i>1){break;}
		i++;
		
		

	}

	//printf("command 1->%s\n",commandl[0] );
	//printf("command 2->%s\n",commandl[1] );
	      
		
		pch = strtok (commandl[0]," "); //Perno thn 1h entolh kai afaiew ta kena

			while (pch != NULL)
			{
				argv1[k]=strdup(pch);
				//printf("%s\n",pch );
				pch = strtok (NULL, " ");
				k++;
			}

	for (i = k; i < 10; i++)
	{
		argv1[i]=NULL;
	}

	for(i=0; i<10; i++){
		argv2[i]=NULL;

	}			

	k=0; //midenizw xana to metrith gia thn epomenh entolh
	pch = strtok (commandl[1]," "); //Perno thn 2h entolh kai afaiew ta kena

			while (pch != NULL)
			{
				argv2[k]=strdup(pch);
				pch = strtok (NULL, " ");
				k++;
			}

	for (i = k; i < 10; i++)
	{
		argv2[i]=NULL;
	}

	//printf("------End of parse----------.\n");
	
}



int main(){

	char command[300];

   	char*  argv1[10]; // 1h entolh
   	char*  argv2[10]; //2h entolh	
   	int fd[2]; //file descriptor
   	
		for(;;){

				printf("$");
				scanf (" %[^\n]%*c", command);

				if(strcmp(command,"exit")==0) {
					   _exit(0);
					};
				
				
				parse(command,argv1,argv2);

				pipe(fd);
			
				pid_t process;


				process = fork();
				

		            //fork error
		            if (process == -1){ // Error wlile creating process

		               perror("Failed to fork..");
		         		               
		            }else if(process==0){ // Child process executes here
		            	
		            	
		            	

		            	if(argv2[0]!=NULL){ //An yparxei 2h entolh tote kanw redirect to output ths 1hs
		            		


			            	dup2(fd[WRITE_END], STDOUT_FILENO);
			            	close(fd[READ_END]);
			    			close(fd[WRITE_END]);     	
			            		

		            	}
		            	
		            	if(execvp(argv1[0],argv1)==-1){
				        	perror("Bad command !\n");
				        	break;
				        }		            		
		                				        	
		          	
		           }else if(process>0){  // Parent process executes here     	

		           			wait(NULL);
		           			
		            		
				        	if(argv2[0]!=NULL){ //An yparxei 2h entolh
				        		pid_t newchild;	//Dhmiourgw 2o child procces
				        		newchild=fork();
				        		
				        		
				        			if(newchild==0){ //Newchild procces
				        				//wait(NULL);
								        close(fd[WRITE_END]);
								        dup2(fd[READ_END], STDIN_FILENO);
								    	close(fd[READ_END]);
								            	
								        if(execvp(argv2[0],argv2)==-1){
								        	perror("Bad command !\n");
								         	break;
								        }	   
		            				

		            				//printf("RETURNED OK\n");
							}
		            		
		            	
		            }
			
					close(fd[WRITE_END]); //Kleinoume to pipe
		            close(fd[READ_END]);
		            wait(NULL); //Kai telos perimenoume na teleiwsei kathe child process
 			}
 		}
            
	return 0;
}