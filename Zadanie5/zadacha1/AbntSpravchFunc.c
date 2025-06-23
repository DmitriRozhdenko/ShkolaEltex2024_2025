#include <stdio.h>
#include <stdlib.h>
	  struct abonent {
			char name[10];
			char second_name[10];
			char tel[10];
	  };
	  
  void MenySpravochnik(unsigned char *vcRabotaFn); 													/// МЕНЮ СПРАВОЧНИКА
  void InputKomandMeny(unsigned char *vcRabotaFn); 													/// ВВОД КОМАНДЫ МЕНЮ
  void AddAbonent(unsigned char *vcCount_AbonentFn,unsigned char *vcRabotaFn,	struct abonent *ptrFn);  /// Выполнение команды
																										 /// " Добавить абонента "
  void DellAbonent(unsigned char *vcCount_AbonentFn,unsigned char *vcRabotaFn,	struct abonent *ptrFn);  /// УДАЛЕНИЕ АБОНЕНТОВ 
  void OutPutAllRecord(unsigned char *vcCount_AbonentFn,unsigned char *vcRabotaFn,struct abonent *ptrFn); /// ВЫВОД ВСЕХ ЗАПИСЕЙ
 void SearchAbonent (unsigned char *vcCount_AbonentFn,unsigned char *vcRabotaFn,struct abonent *ptrFn	); /// ПОИСК АБОНЕНТОВ 

 int main() 
 {  
	unsigned char i,k;
	unsigned char vcCount_Abonent; // счетчик количества абонентов в списке
	unsigned char vcRabota ;		// текущий номер выполняемого блока в switch
		  
	 struct abonent Caller[100]; 	// обьявили 100 абонентов
	 struct abonent *ptrtemp;			
	 
	 //очистка полей справочника
	  for(i=0;i<100;i++)
	   {  
		   ptrtemp=&Caller[i];
		  for(k=0;k<10;k++) 
		   {
			   ptrtemp->name[k]=0;
			   ptrtemp->second_name[k]=0;
			   ptrtemp->tel[k]=0;
		   }
	   }
	   vcRabota=0;
	   vcCount_Abonent=0;
	  
	while(1)
	{
		switch  (vcRabota)
        {
		   case 0:    ///  МЕНЮ СПРАВОЧНИКА
				MenySpravochnik( &vcRabota );
		   break;
		   case 1:     /// ВВОД КОМАНДЫ МЕНЮ
		     InputKomandMeny( &vcRabota );
		   break;
		   case 2:     /// Выполнение команды " Добавить абонента "
				AddAbonent(&vcCount_Abonent, &vcRabota, &Caller[vcCount_Abonent]);
		   break;
		   case 3:     /// УДАЛЕНИЕ АБОНЕНТОВ 
	              
	             DellAbonent(&vcCount_Abonent, &vcRabota,&Caller[0]); 	   
		    break;
		    case 4: /// ПОИСК АБОНЕНТОВ 
		          SearchAbonent (&vcCount_Abonent, &vcRabota, &Caller[0]);
		    break;	    
		    case 5:     /// ВЫВОД ВСЕХ ЗАПИСЕЙ
					OutPutAllRecord(&vcCount_Abonent,&vcRabota,&Caller[0]) ;
		    break;
		    case 6:		/// Выход из меню справочника
		         exit(1);
				vcRabota=0;	
		    break;
		  } 
	}	
	
}	





void MenySpravochnik(unsigned char *vcRabotaFn)
 {
				printf("__________________________ \n");   
				printf("	 МЕНЮ справочника \n");
				printf("			 \n");
				printf("1 - Добавить абонента \n");
				printf("2 - Удалить абонента	\n");
				printf("3-  Поиск абонентов по имени  \n");
				printf("4-  Вывод всех записей  \n");
				printf("5 - Выход  \n");
				printf("__________________________ \n"); 
				printf("			 \n");
				printf("введите пункт меню: ");
			 			
				*vcRabotaFn=1; 
 }	 
 
 void InputKomandMeny(unsigned char *vcRabotaFn)
 {
	unsigned  int vcKomanda ;	// номер команды, вводимой с клавиатуры
    
	scanf("%d",&vcKomanda);
	scanf("%*[^\n]");   // очистка буфера scanf,если ввели больше 10 знаков
	  if((vcKomanda == 0)|| (vcKomanda >5)) //проверка в диапазоне ли вводимая команда меню
	  {
		printf("Нет такого пункта меню \n");

	  }
	  else 
	  {	
		*vcRabotaFn= vcKomanda + 1; 		  				
	  } 
 }	 

void AddAbonent(unsigned char *vcCount_AbonentFn,unsigned char *vcRabotaFn,	struct abonent *ptrFn	)
{
		unsigned char i,k;
		unsigned char Temp[10] ;
		 unsigned char  vcOperaciya ;		// выполняемая операция при добавлении абонента
		
		vcOperaciya = 0;
	    while( vcOperaciya < 3 )
	    {
			printf("			 \n");
				 switch (vcOperaciya)
				     { 
					   case 0:
						   if(*vcCount_AbonentFn < 100) 
							{ printf("введите имя абонента (не больше 10знаков) \n");	
								 for(k=0;k<10;k++) 
								   {
									  Temp[k] =0; 
								   }						
							  scanf("%10s",Temp);
							  scanf("%*[^\n]");   // очистка буфера scanf,если ввели больше 10 знаков	
							 // ptr=&Caller[vcCount_Abonent];
							  for(i=0;i<10;i++)
								{ 
									ptrFn->name[i] = Temp[i];			      
								}
							 vcOperaciya =1;   
							}
							 else 
							 { 
								 printf("превышено количество добавляемых абонентов  \n");
								 *vcRabotaFn=0;
							 }
					      
					   break;						   				   
					   case 1:							    							  						  		     					     
							 printf("введите фамилие абонента (не больше 10знаков) \n");
							     for(k=0;k<10;k++) 
								   {
									  Temp[k] =0; 
								   }	
													
							  scanf("%10s",Temp);
							  scanf("%*[^\n]");   // очистка буфера scanf,если ввели больше 10 знаков	
							  for(i=0;i<10;i++)
								{ 
									ptrFn->second_name[i] = Temp[i];			      
								}
							 vcOperaciya =2;       
					   break;					   
					   case 2:							   			    
							printf("введите номер телефона абонента (не больше 10знаков) \n");
								for(k=0;k<10;k++) 
								   {
									  Temp[k] =0; 
								   }	
								 						
							  scanf("%10s",Temp);
							  scanf("%*[^\n]");   // очистка буфера scanf,если ввели больше 10 знаков	
							  for(i=0;i<10;i++)
								{ 
									ptrFn->tel[i] = Temp[i];			      
								}
									vcOperaciya = 3; 
									*vcRabotaFn = 0;	
								 *vcCount_AbonentFn = *vcCount_AbonentFn +1;
					   break;	
					   	   					 
					 }	
					 
			}	
				 	    
}	
	
/// УДАЛЕНИЕ АБОНЕНТОВ 
void DellAbonent(unsigned char *vcCount_AbonentFn,unsigned char *vcRabotaFn,  //			
		struct abonent *ptrFn	)
 {
	unsigned char i,k;
	unsigned char Temp[10],Temp1[10];
	unsigned char vcDel_Abonent;   //номер абонента,которого нужно удалить	 
	struct abonent	*ptr;
	 struct abonent	*ptrTEMP;
	 unsigned char vcIstina;			// результат сравнения

	              if( *vcCount_AbonentFn > 0) 
	               {
					    printf("ВВЕДИТЕ ИМЯ АБОНЕНТА,КОТОРОГО НУЖНО УДАЛИТЬ\n");
						 for(k=0;k<10;k++) 
						   {
							  Temp[k] =0; 
						   } 
						   
						   scanf("%10s",Temp);
					   		scanf("%*[^\n]");   // очистка буфера scanf,если ввели больше 10 знаков			   
				      printf("ВВЕДИТЕ ФАМИЛИЮ АБОНЕНТА,КОТОРОГО НУЖНО УДАЛИТЬ\n");
						 for(k=0;k<10;k++) 
						   {
							  Temp1[k] =0; 
						   } 
						   
						   scanf("%10s",Temp1);
							scanf("%*[^\n]");   // очистка буфера scanf,если ввели больше 10 знаков	
							vcDel_Abonent = 0;
							// ищем абонента ,которого нужно удалить
					     for(i=0;i < *vcCount_AbonentFn;i++)
					      {
							ptr = &ptrFn[i];
							 vcIstina =0;
							  for(k=0;k<10;k++)
							  {	
								  //проверяем каждый символ в списке абонентов для поиска кого удалить
								if((ptr->second_name[k] == Temp1[k]) && (ptr->name[k] == Temp[k]))	
								{
									vcIstina =1;
							    }	
								else
								 {
									vcIstina =0; 
									break;
								 }						 
							  }  
							  
							 if(vcIstina ==1) 
							  {
								 vcDel_Abonent =i+1;
								 break;
							  } 				 
						  }	  
						  
						  if(vcDel_Abonent > 0)
						   {
							   ptr=&ptrFn[vcDel_Abonent-1];
							   // обнуление полей абонента
							  for(k=0;k<10;k++) 
							   {
								   ptr->name[k]=0;
								   ptr->second_name[k]=0;
								   ptr->tel[k]=0;
							   }
								// сдвинуть абонентов,чтобы не было пустот в списке абонентов при выводе их на экран
							    for(i=(vcDel_Abonent-1);i < *vcCount_AbonentFn; i++)
								   {  
									   ptr=&ptrFn[i];
									   ptrTEMP=&ptrFn[i+1];
									  for(k=0;k<10;k++) 
									   {
										   ptr->name[k]			= ptrTEMP->name[k];
										   ptr->second_name[k]	= ptrTEMP->second_name[k];
										   ptr->tel[k]			= ptrTEMP->tel[k];
									   }
								   }
							   *vcCount_AbonentFn =*vcCount_AbonentFn -1;
						   } 
						   else
						   {
							printf("НЕТ ТАКОЙ ФАМИЛИИ АБОНЕНТА ДЛЯ УДАЛЕНИЯ\n");
							printf("			 \n"); 
						   }  
						}   
						else
						{
						 printf("НЕТ АБОНЕНТОВ В СПИСКЕ\n");
						 printf("			 \n"); 	
					    }		   
						  	*vcRabotaFn=0;	
}

/// ВЫВОД ВСЕХ ЗАПИСЕЙ
void OutPutAllRecord(unsigned char *vcCount_AbonentFn,unsigned char *vcRabotaFn,struct abonent *ptrFn	)
{
	unsigned char i,k;
	struct abonent	*ptr;
	
	 
					if( *vcCount_AbonentFn > 0)
					 {
						 printf("список абонентов\n");
						  printf("			 \n"); 
					     for(i=0; i< *vcCount_AbonentFn;i++)
					      {
							 ptr=&ptrFn[i];
							 printf("%d.  ",i+1);
							 for(k=0;k<10;k++)
							  {	
								  printf("%c",ptr->name[k]);								 
							  }  
							   printf("			 \n"); 
							   printf("  "); 
							  for(k=0;k<10;k++)
							  {	
								  printf("%c",ptr->second_name[k]);								 
							  }  
							   printf("			 \n"); 
							   printf("  "); 
							  for(k=0;k<10;k++)
							  {	
								  printf("%c",ptr->tel[k]);								 
							  }  
							   printf("			 \n"); 	
							   	printf("			 \n");					 
						  }	
						}
						else 
						 { printf("СПИСОК АБОНЕНТОВ ПУСТ\n");
						   printf("			 \n"); 
						 }  
						  	*vcRabotaFn=0;	
}						  		


/// ПОИСК АБОНЕНТОВ 
void SearchAbonent (unsigned char *vcCount_AbonentFn,unsigned char *vcRabotaFn,struct abonent *ptrFn	)
{
		unsigned char vcCount_Sovpadenij;	//счетчик совпадений имен при поиске абонентов
		unsigned char i,k;
		struct abonent	*ptr;
		unsigned char Temp[10];
		unsigned char vcIstina;			// результат сравнения
		
	             if( *vcCount_AbonentFn > 0)
	               {
				      printf("ВВЕДИТЕ ИМЯ АБОНЕНТА,КОТОРОГО НУЖНО НАЙТИ\n");
						 for(k=0;k<10;k++) 
						   {
							  Temp[k] =0; 
						   } 
						   vcCount_Sovpadenij=0;
						   
						   scanf("%*[^\n]");  // очистка буфера scanf,если ввели больше 10 знаков	
						   scanf("%10s",Temp);
						
					     for(i=0;i < *vcCount_AbonentFn;i++)
					      {
							 ptr=&ptrFn[i];
							 vcIstina =0;
							  for(k=0;k<10;k++)
							  {	
								  //проверяем каждый символ в имени абонентов для поиска
								if(ptr->name[k] == Temp[k])	
								{ 
									vcIstina =1;
									
								}	
								else
								 {
									vcIstina =0; 
									break;
								 }						 
							  }  
							  // вывод на экран абонентов с именами,которые просят найти
							 if(vcIstina ==1) 
							  {
								  vcCount_Sovpadenij = vcCount_Sovpadenij+1;
									 printf("%d.  ",vcCount_Sovpadenij);
								 for(k=0;k<10;k++)
								  {	
									  printf("%c",ptr->name[k]);								 
								  }  
								   printf("			 \n"); 
								   printf("  "); 
								  for(k=0;k<10;k++)
								  {	
									  printf("%c",ptr->second_name[k]);								 
								  }  
								   printf("			 \n"); 
								   printf("  "); 
								  for(k=0;k<10;k++)
								  {	
									  printf("%c",ptr->tel[k]);								 
								  }  
								   printf("			 \n"); 	
									printf("			 \n");	
							   } 				 
							 }	  
						 
						 
						   if(vcCount_Sovpadenij == 0)
						   {
							printf("НЕТ ТАКОГО ИМЕНИ В СПРАВОЧНИКЕ\n");
							printf("			 \n"); 
						   }  
					}   
					else
					{
					 printf("СПРАВОЧНИК НЕ ЗАПОЛНЕН \n");
					 printf("			 \n"); 	
					}		   
						  	*vcRabotaFn=0;		
}
