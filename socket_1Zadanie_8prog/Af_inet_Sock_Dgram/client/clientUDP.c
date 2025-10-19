

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

char message[] = "Hello !\n";
char buf[1024];

int main()
{
		int sock;
		socklen_t len;		// обьявили тип для хранения размера структуры клиент
		struct sockaddr_in addr;	//создаем структуру для клиента
		sock = socket(AF_INET, SOCK_DGRAM, 0);	// создаем точку соединения(сокет) и его дискриптор 
		if(sock < 0)
		{
		perror("socket");
		exit(1);
		}
		// заполняем структуру end-point для общения с сервером ,задающей параметры для связывания сокета
		addr.sin_family = AF_INET;
		addr.sin_port = htons(7878);
		addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);   // адрес сервера без выхода в сеть
	
	   len =sizeof(addr);
	   //отправляем данные серверу
		sendto(sock, message, sizeof(message), 0,(struct sockaddr *)&addr,len );	//sizeof(addr)
			//принимаем ответ
		recvfrom(sock, buf, 1024,0,(struct sockaddr *)&addr,&len); 
		printf("%s",buf);

		close(sock);
return 0;

}



