 #include <sys/types.h>
 #include <unistd.h>
#include <sys/wait.h>
 #include <stdlib.h>
// #include <wait.h>
#include <stdio.h>

	pid_t child_pid;			// обьявили пид процесса

 int main() 
 {   
	int status;
	 
	 child_pid = fork();
	 
	if(child_pid == 0)   //  дочерний процесс
	{
		 printf ("child ppid =%d\n",getppid());			//вывести пид родителя процесса 
		 printf ("child pid=%d\n",getpid());			//вывести пид процесса 
		 exit(2);
	}
	else					// родительский процесс
	{
		printf ("parent ppid =%d\n",getppid());
		printf ("parent pid =%d\n",getpid());
		wait(&status); 
		printf ("status =%d\n",WEXITSTATUS(status));
	}
	 
	 return 0;
 } 
 

