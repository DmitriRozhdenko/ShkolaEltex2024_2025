#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char message[] = "Hello!\n";
char buf[sizeof(message)];
int main()
{
		int sock;
		struct sockaddr_in addr;		//создаем структуру для клиента
		sock = socket(AF_INET, SOCK_STREAM, 0);	// создание сокета и его дискриптора
		if(sock < 0)
		{
		perror("socket");
		exit(1);
		}
			//заполняем структуру end-point для общения с сервером ,задающей параметры для связывания сокета
		addr.sin_family = AF_INET;
		addr.sin_port = htons(7878);  
		addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);// адрес сервера без выхода в сеть
		
		if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)// установить соединение с сервером
		{
		perror("connect");
		exit(2);
		}
		send(sock, message, sizeof(message), 0);//отправляем данные серверу
		recv(sock, buf, 1024, 0);				//принимаем ответ
		printf("%s",buf);
		close(sock);
		return 0;

}


