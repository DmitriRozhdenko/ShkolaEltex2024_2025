#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

 #define MY_SOCK_PATH "/tmp/somepath"		// Путь к файловому сокету

int main()
{
 int sock, listener;		
 struct sockaddr_un servaddr;	//создаем структуру для сервера
 char buf[1024];			//приемный буфер пусть будет 1024 байт
 char message[] = "Hi!\n";
 int bytes_read;
 
 unlink(MY_SOCK_PATH);
	listener = socket(AF_LOCAL, SOCK_STREAM, 0);		// создание сокета и его дискриптора 
		if(listener < 0)
		{
		  perror("socket");
		  exit(1);
		}
		memset(&servaddr, 0, sizeof(struct sockaddr_un));// обнулить структуру
	
	// заполнение структуры , задающей параметры для связывания сокета сервера (Привязка сокета к файловому пути)
		servaddr.sun_family = AF_LOCAL;
		strncpy(servaddr.sun_path, MY_SOCK_PATH,sizeof(servaddr.sun_path) - 1);// заполнить поле структуры,путем копирования
		
	//функция связывание сокета с адресом сервера в выбранном домене
		if(bind(listener, (struct sockaddr *)&servaddr, sizeof(struct sockaddr_un)) < 0)
		{
		  perror("bind");
		  exit(2);
		}
	listen(listener,5);//сокет переводится в режим ожидания запросов со стороны клиентов
	
		  sock = accept(listener, NULL, NULL);	//создаём для общения с клиентом новый сокет и возвращает его дескриптор
			if(sock < 0)
			{
			  perror("accept");				// Ошибка принятия соединения
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
			// Закрытие сокетов
	    	close(sock);
	    	close(listener);
			unlink(MY_SOCK_PATH);			// Удаляем файл сокета после завершения
		return 0;
}
