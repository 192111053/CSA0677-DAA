 #include <stdio.h>  
int main()  
{ 
    int n1, n2, i, GCD_Num;  
    int count=0;
    printf ( " Enter any two numbers: \n ");  
    scanf ( "%d %d", &n1, &n2);
	 
    for( i = 1; i <= n1 && i <= n2; ++i)  
    {  
        count++;
        if (n1 % i ==0 && n2 % i == 0)  
            GCD_Num = i; 
            count++;
        }  
		count++; 
		
        printf ("gcd of two numbers %d and %d is %d  ", n1, n2, GCD_Num);  
        printf("time complexity :%d ",count);
        return 0;  
}
