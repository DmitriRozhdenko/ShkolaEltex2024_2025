
/*
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
 int listener;  //sock, 
 struct sockaddr_in servaddr,clientaddr;	//создаем структуру для сервера и клиента
 char buf[1024];							//приемный буфер пусть будет 1024 байт
 char message[] = "Hi!\n";
 int bytes_read;
 socklen_t len;		// обьявили тип для хранения размера структуры клиент
 
	listener = socket(AF_INET, SOCK_DGRAM, 0); //создаем точку соединения(сокет) и его дискриптор 
		if(listener < 0)
		{
		  perror("socket");
		  exit(1);
		}
	// заполнение структуры , задающей параметры для связывания сокета для общения с клиентом
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(7878);
		servaddr.sin_addr.s_addr = htonl(INADDR_ANY);	//соединяться с клиентами через любой интерфейс(адрес)
		//функция связывание сокета с адресом сервера в выбранном домене(связывание сокета с end-point)
		if(bind(listener, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		{
		  perror("bind");
		  exit(2);
		}

		len =sizeof(clientaddr);
			while(1)
			{		// принимаем данные от клиента
				  bytes_read = recvfrom(listener , buf, 1024, 0,(struct sockaddr *)&clientaddr,&len); 
				  if(bytes_read <= 0) break;
					  else printf("%s",buf);
					//	отправляем ответ  
				  sendto(listener ,message, sizeof(message), 0, (struct sockaddr *)&clientaddr,len);	//sizeof(clientaddr)			
				  break;
			}

	    	close(listener );
		
return 0;
}

*/

/* #include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> */
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
 int listener;  
 struct sockaddr_in clientaddr;		
	listener = socket(AF_INET, SOCK_DGRAM, 0); // создание сокета и его дискриптора 
		if(listener < 0)
		{
		  perror("socket");
		  exit(1);
		}
		
	// заполнение структуры 
	clientaddr.sin_family = AF_INET;
	clientaddr.sin_port = htons(7777);
	clientaddr.sin_addr.s_addr = inet_addr("225.0.0.1");
	
	// отправка сообщения мультикастовой  группе
		  sendto(listener ,message, strlen(message), 0, (struct sockaddr *)&clientaddr,sizeof(clientaddr));	
	  
		close(listener );
return 0;
}

