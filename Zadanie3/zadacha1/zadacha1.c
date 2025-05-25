#include <stdio.h>
 int main() {
	long  int viInput ;	//
	 unsigned  int viChislo;		// unsigned 
	  char vcByte ;
	char *ptr1;					// обьявили указатель
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
					vcByte = viInput;
					ptr1 =(char*) &viChislo;	// указателю присвоили адрес ячейки памяти viChislo и 
												// сделали приведение типа unsigned  int viChislo к char
					*(ptr1+2) = vcByte;
					  printf("при замене 3 байта в исходном числе результат = %d\n",viChislo );   
					printf("\n");	
					
				}		
			}	
		}
 
} 
