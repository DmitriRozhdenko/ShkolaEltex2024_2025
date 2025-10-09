
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
/*#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> */

#include <sys/socket.h>
       #include <sys/un.h>
       #include <stdlib.h>
       #include <stdio.h>
       #include <string.h>


char message[] = "Hello !\n";
char buf[1024];

 #define MY_SOCK_PATH "./somepath"

int main()
{
		int sock;
	socklen_t len;		// обьявили тип для хранения размера структуры клиент
		struct sockaddr_un svaddr, claddr;	//создаем структуру для клиента
		sock = socket(AF_LOCAL, SOCK_DGRAM, 0);	// создание сокета и его дискриптора 
		if(sock < 0)
		{
		perror("socket");
		exit(1);
		}
		memset(&claddr, 0, sizeof(struct sockaddr_un));
		// заполнение структуры , задающей параметры для связывания сокета
		claddr.sun_family = AF_LOCAL;
		
		
		//функция связывание сокета с адресом клиента в выбранном домене
		if(bind(sock, (struct sockaddr *)&claddr, sizeof(struct sockaddr_un)) < 0)		//servaddr
		{
		  perror("bind");
		  exit(2);
		}
	// Формируем адрес сервера 
			memset(&svaddr, 0, sizeof(struct sockaddr_un));
			svaddr.sun_family = AF_LOCAL;
			strncpy(svaddr.sun_path, MY_SOCK_PATH,sizeof(svaddr.sun_path) - 1);
	
	len =sizeof(struct sockaddr_un);	//sizeof(addr);
	   //отправляем сообщение серверу
		sendto(sock, message, sizeof(message), 0,(struct sockaddr *)&svaddr,sizeof(struct sockaddr_un) );	//sizeof(addr)
			//принимаем ответ
		recvfrom(sock, buf, 1024,0,(struct sockaddr *)&claddr,&len); 
		//recvfrom(sock, buf, 10,0,NULL,NULL); 
		printf("%s",buf);
		//close(sock);
		remove(claddr.sun_path); 					//Удаляем путь к клиентскому сокету
return 0;

}



