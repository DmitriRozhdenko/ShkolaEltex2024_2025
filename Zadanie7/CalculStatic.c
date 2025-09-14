#include <stdio.h>
#include <stdlib.h>
//#include "add.h"
//#include "sub.h"
//#include "dive.h"
//#include "mul.h"
#include "libcalc.h"

 int main() 
 {    
	  
	long  Result; 					// результат арифметической операции
	long t;							// временная переменная	 
	 unsigned int vcOper;			//выполняемая арифметическая операция
	 unsigned char vcRabota;		// этапы ввода операндов с клавиатуры
	 	  
	 long Operand1; 				// первый операнд арифметической операции	
	 long Operand2; 				// второй операнд арифметической операции		
	 
	   vcRabota=0;

	while(1)
	 { 
		
	   switch  (vcRabota)
        {
		   case 0:
				   
				printf("			МЕНЮ \n");
				printf("			 \n");
				printf("1 - сложить  \n");
				printf("2 - вычесть  \n");
				printf("3-  умножить  \n");
				printf("4 - разделить  \n");
				printf("5 - завершить  \n");
				printf("			 \n");
				printf("введите код операции \n");
				vcRabota=1;
			
		   break;
		   case 1:		// обработка пункта меню
		   
		   scanf("%d",&vcOper);
			scanf("%*[^\n]");   // очистка буфера scanf,если ввели больше 10 знаков
			  if((vcOper== 0)|| (vcOper >5)) //проверка в диапазоне ли вводимая команда меню
			  {
				printf("Нет такого пункта меню \n");
				
			  }
			  else if(vcOper==5)vcRabota=4; 
			   else
				  {
					vcRabota=2; printf("введите первый операнд (не больше 10 знаков) \n");
				  }	  
	   
		   break;
   
		   case 2:			//обработка первого операнда
								scanf("%*[^\n]");   // очистка буфера scanf,если ввели больше 10 знаков		
							  if(scanf("%10ld",&t)>0)											
								{ 
									if( t > 2147483647 ) printf(" превышено введенное число\n"); 
									 else if( t < -2147483648 ) printf(" превышено введенное число\n"); 
									   else
									   {
										  Operand1 = t;
										  printf(" введите второй операнд (не больше 10 знаков)\n"); 
										  vcRabota=3; 
										}  
								}	
								else
								{
									printf(" введен первый символ не цифра\n"); 
								}						  
			 
		 break;
   
		 case 3:		//обработка второго операнда
							scanf("%*[^\n]");   // очистка буфера scanf,если ввели больше 10 знаков	
							if(scanf("%10ld",&t)>0)				
							 {
								if( t > 2147483647 ) printf(" превышено введенное число\n"); 
									 else if( t < -2147483648 ) printf(" превышено введенное число\n"); 
									   else
									   {
										  Operand2 = t;
										  vcRabota = 4; 
										}  
						     }	 										
							  else
							  {
								printf(" введен первый символ не цифра\n"); 
							  }
		 break;
     
           case 4:	//выполнить арифметическую операцию
          
				    switch  (vcOper)
				     {
					   case 1:
					    Result=add( Operand1,Operand2 );
					     printf("сумма %ld\n", Result);
					   break;						   				   
					   case 2:
					     Result=sub(Operand1 ,Operand2 );
					     printf("разность %ld\n", Result);
					   break;					   
					   case 3:
					    Result=mul(Operand1 ,Operand2 );
					     printf("произведение %ld\n", Result);
					   break;					   
					   case 4:
							Result=dive(Operand1 ,Operand2 );
					     printf("деление %ld\n", Result);
					   break;					   
					   case 5:
					     vcRabota=0; 
					      exit(1);
					     printf("завершено \n"); 
					   break;
					}
					if(vcRabota!=6)
					 {
						vcRabota=0;		//5;  
						vcOper =0;
						Operand1 =0;
						Operand2 =0;
				
				     }		 
              break;
              
           
		  }
     }
 } 



