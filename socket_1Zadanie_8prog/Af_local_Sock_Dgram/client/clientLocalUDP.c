
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/socket.h>
 #include <sys/un.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char message[] = "Hello IN!\n";
char buf[1024];

 #define MY_SOCK_PATH "/tmp/somepath"	

int main()
{
		int sock;
	socklen_t len;		// обьявили тип для хранения размера структуры sockaddr_un
		struct sockaddr_un svaddr, claddr;	//создаем структуру для клиента
		sock = socket(AF_LOCAL, SOCK_DGRAM, 0);	// создание сокета и его дискриптора 
		if(sock < 0)
		{
		perror("socket");
		exit(1);
		}
		memset(&claddr, 0, sizeof(struct sockaddr_un));// обнулить структуру
		// заполнение структуры , задающей параметры для связывания сокета для общения с сервером
		claddr.sun_family = AF_LOCAL;
		//strncpy(claddr.sun_path, MY_SOCK_PATH,sizeof(claddr.sun_path) - 1);//claddr
		
		//функция связывание сокета с адресом клиента в выбранном домене
		if(bind(sock, (struct sockaddr *)&claddr, sizeof(struct sockaddr_un)) < 0)		//servaddr
		{
		  perror("bind");
		  exit(2);
		}
	// Формируем адрес сервера 
			memset(&svaddr, 0, sizeof(struct sockaddr_un));// обнулить структуру
			svaddr.sun_family = AF_LOCAL;
		strncpy(svaddr.sun_path, MY_SOCK_PATH,sizeof(svaddr.sun_path) - 1);// заполнить поле структуры,путем копирования
	
	len =sizeof(struct sockaddr_un);	
	   //отправляем сообщение серверу
		sendto(sock, message, sizeof(message), 0,(struct sockaddr *)&svaddr,sizeof(struct sockaddr_un) );	
			//принимаем ответ
		recvfrom(sock, buf, 1024,0,(struct sockaddr *)&svaddr,&len); 
	//	recvfrom(sock, buf,1024,0,NULL,NULL); 
	
		printf("%s",buf);
		close(sock);
		
return 0;

}



