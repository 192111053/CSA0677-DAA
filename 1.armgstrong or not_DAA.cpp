#include<stdio.h>  
int main()    
    {    
    int n,r,sum=0,temp;    
    int count=0;
    printf("enter the number=");    
    scanf("%d",&n);    
    temp=n;    
    while(n>0)    
    {    
    count++;
    r=n%10;   
	count++; 
    sum=sum+(r*r*r);  
	count++;   
    n=n/10; 
	count++;    
    }    
    count++;
    if(temp==sum)  
	printf("true \n"); 
	else 
    printf("false \n");    
    printf("the total counters are %d",count);
    return 0;  
}
