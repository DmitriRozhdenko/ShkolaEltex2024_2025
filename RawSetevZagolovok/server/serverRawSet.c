
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
 int listener;   
 struct sockaddr_in servaddr,clientaddr;	//создаем структуру для сервера и клиента
 char buf[1024];							//приемный буфер пусть будет 1024 байт
 int bytes_read;						 // количество принимаемых байт
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
		servaddr.sin_addr.s_addr = htonl(INADDR_ANY);	//соединяться с клиентами через любой интерфейс(адрес)INADDR_LOOPBACK
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
				  else 
				   { 
					  printf("%s",buf);
					  buf[0]=' ';
					   //	отправляем ответ  без первой буквы
					sendto(listener ,buf, bytes_read, 0, (struct sockaddr *)&clientaddr,len);	//sizeof(clientaddr)
					break;
				   }   
												  
			}
			 printf("\n");
	    	close(listener );
		
return 0;
}

