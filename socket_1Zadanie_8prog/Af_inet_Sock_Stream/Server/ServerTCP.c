#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
 int sock, listener;		
 struct sockaddr_in addr;	//создаем структуру для сервера
 char buf[1024];			//приемный буфер пусть будет 1024 байт
 char message[] = "Hi!\n";
 int bytes_read;
 
	listener = socket(AF_INET, SOCK_STREAM, 0);		//создаем точку соединения(сокет) и его дискриптор  
		if(listener < 0)
		{
		  perror("socket");
		  exit(1);
		}
		// заполнение структуры , задающей параметры для связывания сокета(для общения с клиентом)
	addr.sin_family = AF_INET;
	addr.sin_port =htons(7878);		//
	addr.sin_addr.s_addr = htonl(INADDR_ANY);	//соединяться с клиентами через любой интерфейс(адрес)
	//функция связывание сокета с адресом сервера в выбранном домене
		if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
		{
		  perror("bind");
		  exit(2);
		}
	listen(listener, 1);//сокет переводится в режим ожидания запросов со стороны клиентов
	
		  sock = accept(listener, NULL, NULL);	//создаём для общения с клиентом новый сокет и возвращает его дескриптор
			if(sock < 0)
			{
			  perror("accept");
			  exit(3);
			}
			while(1)
			{
			  bytes_read = recv(sock, buf, 1024, 0);	// принимаем данные от клиента
			  if(bytes_read <= 0) break;
			  else printf("%s",buf);
			 
			  send(sock, message, sizeof(message), 0);	//	отправляем ответ 
			  break;
			}
	    	close(sock);
	    	close(listener);
	
		return 0;
}
