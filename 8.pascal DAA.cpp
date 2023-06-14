#include<stdio.h>
int main() 
{
   int rows, coef = 1, space, i, j;
   int count=0;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (i = 0; i<rows; i++) 
   {
   	  count++;
      for (space = 1; space <= rows - i; space++)
         printf("  ");
         count++;
      for (j = 0; j <= i; j++) 
	  {
	  	 count++;
        if(j == 0 || i == 0){
            coef = 1;
            count++;
        }
            
        else
         {
            coef = coef * (i - j + 1) / j;
         }
            count++;
         printf("%4d", coef);
      }
      printf("\n");
      count++;
   }
   printf("%d",count);
}
