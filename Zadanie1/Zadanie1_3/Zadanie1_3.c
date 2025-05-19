#include <stdio.h>

 int main() {
	 long  int viInput ;	//
	 unsigned  int viTemp ;		// 
	  unsigned  int viCounter;
	 int i;
		while(1)
		{   printf("Введите число не больше 4294967295\n");			
			scanf("%lu",&viInput);
			viCounter = 0;	
			if(viInput > 4294967295)
			{	printf("Введено число большее 4294967295\n");
				printf("\n");
			}
			else
			{	
				for(i=31;i>=0;i=i-1)
				   {
					   viTemp=viInput >> i;
					   viTemp=viTemp & 0x01;				   	
					 if(viTemp == 1) viCounter = viCounter + 1;								
				   }
				printf("количество единиц в числе %d\n", viCounter );    
				printf("\n");   
				printf("\n");	
			}		
		}
 
} 
