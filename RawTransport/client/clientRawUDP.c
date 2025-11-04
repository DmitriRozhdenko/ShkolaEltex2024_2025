#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <linux/udp.h>

char message[] = "Hello !\0";
            
int main()
{
		int sock;
		int i;			
		socklen_t len;
		struct sockaddr_in addr;	//создаем структуру для клиента для сокета AF_INET
	    struct udphdr *udp;			// указатель udp заголовка
		char buf[64];  
		char rcv[92];
		memset(buf, 0, sizeof(buf));
		memset(rcv, 0, sizeof(rcv));
		udp=(struct udphdr *)buf;					//указатель udp,указать на buf,чтобы buf заполнить в формате udp
		sock = socket(AF_INET,SOCK_RAW ,IPPROTO_UDP);		// создаем точку соединения(сокет) и дискриптор сокета RAW
			if(sock < 0)
			{
			perror("socket");
			exit(1);
			}
	//  заполняем структуру end-point для отправки серверу 		
		addr.sin_family = AF_INET;
    	addr.sin_port = htons(7878);
		addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // INADDR_ANY 
	    len =sizeof(addr);
	 //  заполняем транспортный уровень для отправки серверу 	   
	    udp->dest = htons(7878); //порт сервера,приводим в формат сетевой
	    udp->source = htons(3000);//порт клиента,приводим в формат сетевой
	    udp->check = 0;	     
	    udp->len = htons(64);// длина посылки ,берём больше чем хотим отправить
	   
	    // printf("%ld",strlen(message));
	    strncpy(buf+8,message,strlen(message)); // добавить к заголовку транспортного уровня передаваемое сообщение
	  
		sendto(sock, buf, 64, 0,(struct sockaddr *)&addr,sizeof(addr));  // отправить сообщение Hello !
	while(1)
     {
		recvfrom(sock, rcv, 28+64,0,(struct sockaddr *)&addr,&len); //трансп(8)+сетевой(20)+приемные данныеt=
		
		udp = (struct udphdr *)((char *)rcv + 20);//указатель udp указать на приёмный буфер,в который входит 
												//транспортный заголовок и данные,перепрыгнув сетевой(ip) заголовок		
		if(ntohs(udp->dest) == 3000)break;	// слушать порт,который настроен на приём
			
     }

	   for (i = 28; i < 92;i ++)
	    { // выводить приёмный буфер, минуя сетевой (20 байт) и транспортный уровень (8 байт)
			printf("%c",rcv[i]);	
		}

		printf("\n");
		close(sock);
return 0;

}
