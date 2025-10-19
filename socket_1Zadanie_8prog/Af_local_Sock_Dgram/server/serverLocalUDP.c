
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

 
 #define MY_SOCK_PATH "/tmp/somepath"	

 
int main()
{
 int listener; 
 struct sockaddr_un servaddr,clientaddr;	//создаем структуру для сервера и клиента
 char buf[1024];							//приемный буфер пусть будет 1024 байт
 char message[] = "Hi!\n";
 int bytes_read;
 socklen_t len;		// обьявили тип для хранения размера структуры sockaddr_un
 
 unlink(MY_SOCK_PATH);
	listener = socket(AF_LOCAL, SOCK_DGRAM, 0); // создание сокета и его дискриптора 
		if(listener < 0)
		{
		  perror("socket");				//Ошибка создания сокета
		  exit(1);
		}
		memset(&servaddr, 0, sizeof(struct sockaddr_un));// обнулить структуру

	// заполнение структуры , задающей параметры для связывания сокета сервера(Привязка сокета к файловому пути)
		servaddr.sun_family = AF_LOCAL;
		strncpy(servaddr.sun_path, MY_SOCK_PATH,sizeof(servaddr.sun_path) - 1);// заполнить поле структуры,путем копирования

		//функция связывание сокета с адресом сервера в выбранном домене
		if(bind(listener, (struct sockaddr *)&servaddr, sizeof(struct sockaddr_un)) < 0)		
		{
		  perror("bind");			// Ошибка привязки сокета
		  exit(2);
		}

		len =sizeof(struct sockaddr_un);			//sizeof(clientaddr);
			while(1)
			{		// принимаем данные от клиента
				  bytes_read = recvfrom(listener , buf, 1024, 0,(struct sockaddr *)&clientaddr,&len); 
				  if(bytes_read <= 0) break;
					  else printf("%s",buf);	
					//	отправляем ответ  
				  sendto(listener ,message, sizeof(message), 0, (struct sockaddr *)&clientaddr,len);	//sizeof(clientaddr)			
				  break;
			}

			close(listener );			// Закрытие сокета
			unlink(MY_SOCK_PATH);		// Удаляем файл сокета после завершения
return 0;
}

