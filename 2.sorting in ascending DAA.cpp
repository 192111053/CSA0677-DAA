#include <stdio.h>
int main()
{
int i, low, high, mid, n, key, array[100];
int count=0;
printf("Enter number of elements");
scanf("%d",&n);
printf("Enter %d integers", n);
for(i = 0; i < n; i++)
scanf("%d",&array[i]);
printf("Enter value to find");
scanf("%d", &key);
low = 0;
count++;
high = n - 1;
count++;
mid = (low+high)/2;
count++;
while (low <= high) {
	count++;
if(array[mid] < key)
low = mid + 1;
else if (array[mid] == key) {
count++;	
printf("%d found at location %d ", key, mid+1);
break;
}
else
high = mid - 1;
mid = (low + high)/2;
count++;
}
if(low > high)
printf("Not found! %d isn't present in the list.n", key);
printf("time complexity : %d",count);
return 0;
} 
