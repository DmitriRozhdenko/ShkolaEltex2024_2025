
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

char buf[1024];


int  main()
{
	   
		int sock;
		socklen_t len;
		struct sockaddr_in addr;
		sock = socket(AF_INET, SOCK_DGRAM, 0);
		if(sock < 0)
		{
			perror("socket");
			exit(1);
		}
		// заполнение структуры ,задающей параметры для получения сообщений Broadcast
		addr.sin_family = AF_INET;
		addr.sin_port = htons(7777);
		addr.sin_addr.s_addr = inet_network("255.255.255.255");  
		
		//функция связывание сокета с адресом сервера в выбранном домене(связывание сокета с end-point) 
        if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	     {
		   perror("bind");
		   exit(2);
		 }
	   len =sizeof(addr);
	
		recvfrom(sock, buf,1024,0,(struct sockaddr *)&addr,&len); 

		printf("%s",buf);

		close(sock);
return 0;

}
