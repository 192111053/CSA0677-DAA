#include <stdio.h> 
int main()  
{  
int a[10][10],b[10][10],mul[10][10],r,c,i,j,k,count=0;  
printf("enter the number of row=");                     
count++;    
scanf("%d",&r);    
count++;                                                             
printf("enter the number of column="); 
count++;   
scanf("%d",&c);  
count++;  
printf("enter the first matrix element=\n"); 
count++;   
for(i=0;i<r;i++)    
{    
for(j=0;j<c;j++)    
{    
scanf("%d",&a[i][j]);  
} 
count++;    
}    
printf("enter the second matrix element=\n");  
count++;  
for(i=0;i<r;i++)    
{    
for(j=0;j<c;j++)    
{    
scanf("%d",&b[i][j]);    
} 
count++;   
}    
printf("multiply of the matrix=\n");  
count++;  
for(i=0;i<r;i++)    
{    
for(j=0;j<c;j++)        
{    
mul[i][j]=0;    
for(k=0;k<c;k++)    
{    
mul[i][j]+=a[i][k]*b[k][j];      
}  
}  
count++;  
}       
for(i=0;i<r;i++)    
{    
for(j=0;j<c;j++)    
{   
printf("%d",mul[i][j]);
count++;   
}   
printf("\n");
count++;    
}  
printf("total no of counts is:%d",count);
}

