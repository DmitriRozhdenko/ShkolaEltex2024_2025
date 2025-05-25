#include <stdio.h>

 int main() {
	char vcStroka[80] ;		//обьявление массива вводимой строки 
	 char vcSubstring[80] ;	//	обьявление массива вводимой подстроки
	 char i,y;
	char *ptr1;					// обьявили указатель
	char *ptr2;					// обьявили указатель
	char  vcCnt_Substring;		// СЧЕТЧИК символов подстроки
	char vcCounter;				// счетчик количества символов,которые соппале в строке и подстроке


	vcCnt_Substring =0;
	 vcCounter =0;
	 ptr2 =(char *)&vcSubstring;
		 printf("Введите начальную строку не больше 80 символов без пробелов латиницей\n");			
			scanf("%80s",vcStroka);
				printf("Введите подстроку не больше 80 символов без пробелов латиницей\n");
				scanf("%80s",vcSubstring);
		
				ptr1 =(char *)&vcStroka; 
				 
				 // определить сколько символов в подстроке
				for(i = 0; i < 80; i = i + 1)
				   {  if(*(ptr2+i) != '\0')
					   {
						  vcCnt_Substring = vcCnt_Substring +1;
					   }
					   else break;	   					  
					}
				//printf(" %d",vcCnt_Substring); 
						
				 printf("\n"); 
				 y=0;
				 //процедура проверки подстроки в строке
				 for(i = 0; i < 80; i = i+1)
				   { 
					  for(y = 0; y< vcCnt_Substring;y=y+1 ) 
					  {
						   if(*(ptr1+i+y) == *(ptr2+y))
						   {
							  vcCounter = vcCounter +1;
							}	
							else { vcCounter = 0; 
								break;
							}
					  }
					  if(vcCounter != 0)break;
					  else if(i <=vcCnt_Substring) continue;
						else break;
						
					}
					//вывод подстроки ,если она есть в строке
					if(vcCounter !=0)	
					 {
						 for(i = 0; i < vcCnt_Substring; i = i + 1)
						   { 
							  printf(" %c",*ptr2);  
							  ptr2 = ptr2+1; 
							  
							}  
					 }	
					 else
					 {
						printf("НЕ найдена подстрока\n"); 
						ptr2 =NULL;
					}
					
			
 
} 
