#include <stdio.h>
int main() {
  int n;
  int count=0;
  double arr[100];
  printf("Enter the number of elements (1 to 100): ");
  scanf("%d", &n);
  count++;
  for (int i = 0; i < n; ++i) {
  	count++;
    printf("Enter number%d: ", i + 1);
    scanf("%lf", &arr[i]);
  }
  for (int i = 1; i < n; ++i) {
  	count++;
    if (arr[0] < arr[i]) {
      arr[0] = arr[i];
    }
    count++;
  }
  printf("Largest element = %.2lf  ", arr[0]);
  printf("%d",count);
  return 0;
}
