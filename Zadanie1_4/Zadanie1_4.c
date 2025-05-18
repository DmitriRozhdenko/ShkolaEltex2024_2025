#include <stdio.h>

 int main() {
	 long  int viInput ;	//
	 unsigned  int viChislo;		// 
	  unsigned  int viByte;

		while(1)
		{   printf("Введите начальное число не больше 4294967295\n");			
			scanf("%lu",&viInput);
			if(viInput > 4294967295)
			{	printf("Введено число большее 4294967295\n");
				printf("\n");
			}
			else
			{
				viChislo = viInput;
				printf("Введите третий байт не больше 255\n");			
				scanf("%lu",&viInput);
				if(viInput > 255)
				{	printf("Введено число большее 255\n");
					printf("\n");
				}
				else
				{
						viByte = viInput;
						  viChislo =(viChislo & 0xff00ffff)|(viByte<<16);
						  printf("замена 3 байта в исходном числе %d\n",viChislo);   
						printf("\n");	
					
				}		
			}	
		}
 
} 

