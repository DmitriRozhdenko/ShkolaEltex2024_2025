
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
 #include <netinet/ip.h> 
#include <netinet/in.h> 


   char buf[1024]; 
int main()
{  
	 
	   struct ip_mreqn  imr;
		int sock;
		socklen_t len;
		struct sockaddr_in addr;
		 	
		sock = socket(AF_INET, SOCK_DGRAM, 0);
		if(sock < 0)
		{
		perror("socket");
		exit(1);
		}		
		addr.sin_family = AF_INET;
		addr.sin_port = htons(7777);
		addr.sin_addr.s_addr = htons(INADDR_ANY); // 
		 if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	     {
		   perror("bind");
		   exit(2);
		 }	
		
	      imr.imr_multiaddr.s_addr =inet_addr("225.0.0.1");  /* IP-адрес группы */  
          imr.imr_address.s_addr = htons(INADDR_ANY);// (INADDR_ANY); /* IP локального интерфейса */   
          imr.imr_ifindex=0;   /* индекс интерфейса */	 
         setsockopt(sock,IPPROTO_IP,IP_ADD_MEMBERSHIP  ,&imr,sizeof(imr)); //IP_MULTICAST_LOOP  
       	
		   
        len =sizeof(addr);
		recvfrom(sock, buf,1024,0,(struct sockaddr *)&addr,&len); 		
	//	printf("%ld",strlen(buf));
	printf("%s",buf);

		close(sock); 
return 0;

}
