
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

int main()
{
 char message[] = "Hello !\0";
 int listener,val;  
 struct sockaddr_in clientaddr;		
 
	listener = socket(AF_INET, SOCK_DGRAM, 0); // создание сокета и его дискриптора 
		if(listener < 0)
		{
		  perror("socket");
		  exit(1);
		}
		val=1;
	setsockopt(listener,SOL_SOCKET,SO_BROADCAST,&val,sizeof(val));	
		
	 // заполнение структуры ,задающей параметры для отправки сообщений Broadcast
	clientaddr.sin_family = AF_INET;
	clientaddr.sin_port = htons(7777);
	clientaddr.sin_addr.s_addr = inet_network("255.255.255.255");

		  sendto(listener ,message, strlen(message), 0, (struct sockaddr *)&clientaddr,sizeof(clientaddr));		//
	  
		close(listener );
return 0;
}

