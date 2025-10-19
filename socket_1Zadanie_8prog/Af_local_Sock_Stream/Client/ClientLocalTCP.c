#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/socket.h>
 #include <sys/un.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

 #define MY_SOCK_PATH "/tmp/somepath"

char message[] = "Hello!\n";
char buf[sizeof(message)];

int main()
{
		int sock;
		struct sockaddr_un claddr;	//создаем структуру для клиента
		sock = socket(AF_LOCAL,SOCK_STREAM , 0);	// создание сокета и его дискриптора 
		
		if(sock < 0)
		{
		perror("socket");
		exit(1);
		}
		/* Формируем адрес сервера и выполняем соединение */
		
		memset(&claddr, 0, sizeof(struct sockaddr_un)); // обнулить структуру
		// заполнение структуры , задающей параметры для связывания сокета для общения с сервером
		claddr.sun_family = AF_LOCAL;
		strncpy(claddr.sun_path, MY_SOCK_PATH,sizeof(claddr.sun_path) - 1);
				
		if(connect(sock, (struct sockaddr *) &claddr,sizeof(struct sockaddr_un)) < 0)// установить соединение с сервером
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


