#include<stdio.h>
int main(){
    char val[25];
    printf("enter the value: ");
    scanf("%s",&val);
    int count=0,c=0;
    while (val[count]!='\0'){
        count++;
        c++;
    }c++;
    for(int i=count-1;i>=0;i--){
        c++;
        printf("%c",val[i]);
    }c++;
    printf("\ncount: %d",c);
}
