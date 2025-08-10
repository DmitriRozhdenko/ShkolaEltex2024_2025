 #include <sys/types.h>
 #include <unistd.h>
 #include <sys/wait.h>

#include <stdio.h>
 #include <stdlib.h>
 
	pid_t child_pid[5];		// обьявили пид пяти процесов


 int main() 
 {   
	  int status;
					
	 child_pid[0]=fork();			//создали процесс 1
	 
	 if(child_pid[0] == 0)		//  дочерний процесс 1
	  {
			printf ("ppid1 =%d\n",getppid());		//выводим ppid 1 процесса
			printf ("pid1=%d\n",getpid());			//выводим pid 1 процесса
			
			child_pid[2]=fork();				//создали процесс 3
			if(child_pid[2] == 0) 				//  дочерний процесс  3
	      {
				printf ("ppid3 =%d\n",getppid());
				printf ("pid3=%d\n",getpid());
				exit(3);						//завершить процесс 3 со стастусом 3
	      }	  
		 else							// родительский процесс 1
		   {
				child_pid[3]=fork(); 	//создали процесс 4
			   if(child_pid[3] == 0)				 //  дочерний процесс 4
					{
						printf ("ppid4 =%d\n",getppid());
						printf ("pid4=%d\n",getpid());
						exit(4);	//завершить процесс 4 со стастусом 4
					} 
					else
						{
							wait(&status); 	// ожидает процесс 1 завершение процесса 4						
						}
				wait(&status);				// ожидает процесс 1 завершение процесса 3	
			}
		exit(1);							//завершить процесс 1 со стастусом 1
	  }
     else if(child_pid[0] != 0)  // родительский процесс main
	   {
			printf ("Идентификатор процесса main с pid=%d\n",getpid());
			printf ("Идентификатор родителя main с ppid=%d \n",getppid());
			child_pid[1] = fork();				 //создали процесс 2
			if(child_pid[1] == 0)
			{
				printf ("ppid2 =%d\n",getppid());
				printf ("pid2=%d\n",getpid());
				
				child_pid[3]=fork();  			//создали процесс 5
				if(child_pid[3]==0)
				{
					printf ("ppid5 =%d\n",getppid());
					printf ("pid5=%d\n",getpid());
						exit(5);				//завершить процесс 5 со стастусом 5
				}
				else 
				{
					wait(&status);				// ожидает процесс 2 завершение процесса 5
					exit(2);					//завершить процесс 2 со стастусом 2
				}
					 
			}
			else
			{
					wait(&status);				// ожидает main завершение процесса 2
			}
			wait(&status);						// ожидает main завершение процесса 1
		}
	 
	 return 0;
 } 
 

