#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define READ_END 0
#define WRITE_END 1


/***********LINKED LIST***************/
typedef struct pipelist { // Orizw ena linked list

	char *arguments[10]; // Edw tha apothikeute kathe entolh me ta orismata ths
	struct pipelist *next; //Deikths pou deixnei ston epomeno kombo

} Node; 


void insertNode(char *argv[10],Node *head){ //Eisagei  neo kombo sth lista

	int k=0;
	Node * current = head;

    while (current->next != NULL) {
        current = current->next;
    }

     /* twra prosthetw neo kombo*/
    current->next = (Node *)malloc(sizeof(Node));


    for(k=0; k<10; k++){
		current->arguments[k]=argv[k]; //Prostheto sto newnode thn entolh me kathe orismata ths
		//printf("Mesa sto insretnode:%s\n",argv[k] ); 
		}

    current->next->next = NULL;   


}

int print_list(Node * head) { //Typwnei th lista. Proairetika ftiaxthke gia to debugging
	int c;
	printf("\n**********Print list*******\n");
    Node* current = head;


   while (current != NULL) {
    	for(c=0; c<10; c++){
        printf("Orisma==> %s\n", current->arguments[c]);
        
    	}
    	printf("\t\n");
        current = current->next;	

    }
    return 0;
}


int listLength(Node* head) //Epistrefei to megethos ths listas
{
  Node *cur = head;
  int size = 0;

  while (cur != NULL)
  {
    size++;
    cur = cur->next;
  }

  return size-1; //O teleuteos kombos einai kenos
}

void deleteList(Node ** head){ //Diagrafei oloklhrh th lista apo th mnhmh
	 Node *cur = *head;

	 while(cur!=NULL){
	 	free(cur);
	 	cur=cur->next;
	 }


	 *head = NULL;
}


void  parse(char *command,Node *head) //Edw kanoume parsing sthn entolh pou doyhike
{
	char *args[10]; //Dianisma pou apothikeuontai oi entoles pou dinei o xrhsths
	//char *commandl;
	char *tmp_args[10];//Prwsorino dianysma gia metafora sth lista
    char *pch;         //Pernei token pou prokyptoun apo strtok("|");
    char *brs;		   //Pernei token pou prokyptoun apo strtok(" ");
    int cm=0; //aritmos entolwn
    int i=0;
    int k=0; //to k einai o metriths twn orismatwn



     pch = strtok (command,"|"); //Ksexorizw thn kath entolh kai thn apothkeuw  sto args[]
	


	while (pch != NULL)
	{			
		args[i]=strdup(pch); //Save each command separated by "|"
		//printf("%s\n",pch );
		pch = strtok (NULL, "|");
		
		i++;
		cm++; //Ayxanw to metrhth entown
		
	}

	for(i=0; i<10; i++){ // Kanw NULL to dianisma tmp_args
		tmp_args[i]=NULL;
	}


	for(i=cm; i<10; i++){//Kanw NULL to dianisma entolw (gia asfaleia)
		args[i]=NULL;
	}

	
	i=0;   //Anatrexw th lista twn entolwn pou dothikan

	while(args[i]!=NULL){ //Gia kathe entolh pou yparxei sto args afairw ta kena

		brs=strtok(args[i]," ");
		k=0;
			while(brs!=NULL){
				
				//****INSERT TO LIST******
				tmp_args[k]=strdup(brs);
				
				brs=strtok(NULL," ");
				k++;
			}

			for(cm=k; cm<10; cm++){ //Kanw NULL ta stoixeia meta to telos twn orismatwn
				tmp_args[cm]=NULL;
			}

			insertNode(tmp_args,head);

			
		i++;	
	}

	


	//printf("------End of parse----------.\n");
	
}


void executeCmd(Node * head){
			
			int i,k=0;
			int status,pipes_num;			
			
			Node *curr=head;
			pipes_num=listLength(head)-1;// Gia n entole tha exoume n-1 pipes						
		    int fd[2*pipes_num];


		    for(i = 0; i < pipes_num; i++){ //Arxikopoio ta pipes
		        if(pipe(fd + i*2) < 0) { //Kanw pipe anamesa sta file descriptors 0-1==2-3==4-5==.....
		            perror("Couldn't Pipe");
		            exit(EXIT_FAILURE);
		        }
    		}
			
			pid_t process;
   			
   			

		    for (i = 0; i < listLength(head); ++i) { //Anatrexoume kath entolh ths listas



		        process = fork(); //Kanoume fork gia kathe mia rntolh

		        if(process<0){

		        	perror("Failed to fork..");

		        }else if(process == 0) {// CHILD EXECUTES HERE 
		           
		            if(i < listLength(head)-1){ //Elegxoume gia endiameses entoles
		                
		                dup2(fd[k + 1], STDOUT_FILENO); // Kanw duplicate WRITE_END tou pipe (1,3,5...) me 
		                	                    	                
		            }										// to STDOUT.

		            
		            if(k != 0 ){ //To k tha einai 0 mono sthn prwth entolh
		                
		                dup2(fd[k-2], STDIN_FILENO); // Kanw duplicate to READ_END tou pipe (0,2,4...) me to STDIN
		                								  
		            }

		            for(i = 0; i < 2*pipes_num; i++){ //Kleino ola pipes
		                    close(fd[i]);
		            }

		            if( execvp(curr->arguments[0], curr->arguments) < 0 ){
		                    perror("Error while executing comand...");
		                    
		            }
		       		


		        }else if(process>0){ //FATHER 

		        	k=k+2;
		       		curr=curr->next; //Pernw thn epomenh entolh

		        }

		        
		    }


			    for(i = 0; i < 2 * pipes_num; i++){
			        close(fd[i]);
			    }

			    for(i = 0; i < pipes_num + 1; i++){ //Perimenw kathe child na termatisei
			    
			        wait(&status);
				}		    
				
}



int main(){

	char command[200];

	


	for(;;){

	Node *head=(Node *)malloc(sizeof(Node)); //Arxikopoio th lista
	head->next=NULL;	

	printf("$");	
	scanf (" %[^\n]%*c", command);
	if(strcmp(command,"exit")==0) {
		 _exit(0);
	}


	parse(command,head);

   	executeCmd(head); 	


   	//print_list(head);

   	deleteList(&head);

   
  }
	
	printf("RETURNED OK!\n");
	return 0;
}