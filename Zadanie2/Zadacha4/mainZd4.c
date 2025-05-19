#include <stdio.h>

#define N 5					// определение размерности квадратной матрицы


int main() {
	unsigned char a[N][N];		//объявление квадратной матрицы
     unsigned char i; 			 //счетчик строк 
     unsigned char y;   		//счетчик столбцов
     unsigned char	count;		// значение элементов матрицы
     unsigned char prochod;   	// количество циклов проходов для вычисления матрицы
								// улиткой.Каждый проход состоит из прохождения по четырем сторонам

       count=0;
   for(prochod=0;prochod<N/2+1;prochod=prochod+1)	//определение количества проходов для получения матрицы в виде улитке
    {       i=prochod;
		   for(y=prochod;y<(N-prochod);y=y+1)		//вычисление элементов матрицы слева направо
		   {   count=count+1;
				a[i][y]=count;						 								
			} 
				
			y=N-prochod-1;							//вычисление элементов матрицы сверху вниз(правая сторона)		
			 for(i=prochod+1;i<N-prochod;i=i+1)
		   {   count=count+1;
				a[i][y]=count;						 							
			} 
			 i=N-prochod-1;							//вычисление элементов матрицы справа налево
		   for(y=N-prochod-2;y>prochod;y=y-1)
		   {   count=count+1;
				a[i][y]=count;		
				
			} 
			y=prochod;					
			 for(i=N-prochod-1;i>prochod;i=i-1)	//вычисление элементов матрицы снизу вверх(левая сторона)	
		   {   count=count+1;
				a[i][y]=count;						 							
			} 

	}		 
     //	вывод матрицы в виде улитки
     for(i=0;i<N;i=i+1)
      {
        for(y=0;y<N;y=y+1)
        {  
       printf(" %d",a[i][y]); 
      
        }
         printf(" \n");
       }
} 


