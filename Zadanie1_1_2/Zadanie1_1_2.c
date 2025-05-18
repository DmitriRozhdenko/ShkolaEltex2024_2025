#include <stdio.h>

 int main() {
	 long  int viInput ;	//
	 unsigned  int viTemp ;		// 
	 int i;
		while(1)
		{   printf("Введите число не больше 4294967295\n");			
			scanf("%lu",&viInput);	
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
					   printf("%d", viTemp);								
				   }
				printf("\n");   
				printf("\n");	
			}		
		}
 
} 
