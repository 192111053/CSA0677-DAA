//multiplication of matrix//

#include<stdio.h>

int main()
{
    int a[10][10],b[10][10],mul[10][10];

    int i,j,m,n,p,q,count=0,sum=0;

    printf("Enter the rows and columns of first matrix: ");
    count++;

    scanf("%d %d",&m,&n);
    count++;

    printf("Enter the elements of the first matrix: \n");
    count++;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            count++;
        }
    }

    printf("Enter the rows and columns of second matrix: ");
    count++;

    scanf("%d %d",&p,&q);
    count++;

    if(n!=p)
    {
        printf("The multiplication isn't possible");
        count++;
    }
    else
    {
        printf("Enter the elements of the second matrix: \n");
        count++;

        for(i=0;i<p;i++)
        {
            for(j=0;j<q;j++)
            {
                scanf("%d",&b[i][j]);
                count++;
            }
        }
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            for(int k=0;k<p;k++)
            {
                sum = sum + a[i][k]* b[k][j];
            }
            mul[i][j]=sum;
            sum=0;
        }
    }

    printf("Matrix multiplication is: \n");

    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%d\t",mul[i][j]);
            count++;
        }
        printf("\n");
    }

    printf("The time complexity is: %d\n",count);

    return 0;
}
