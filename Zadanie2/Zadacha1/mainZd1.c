#include <stdio.h>

#define N 3	// определение размерности квадратной матрицы


int main() {
	unsigned char a[N][N];   //объявление квадратной матрицы
	unsigned char count;	// значение элементов матрицы
     unsigned char i,y;
     count=0;
   for(i=0;i<N;i=i+1)		//счетчик строк
   {
        for(y=0;y<N;y=y+1)  //счетчик столбцов
        {
			count=count+1;
          a[i][y]=count;
         printf(" %d",a[i][y]); 
        }
        printf(" \n");
    }    
} 
 
  
