#include <stdio.h>
#include <stdlib.h>
int count=0;
void merge(int* nums1, int m, int* nums2, int n) {
	count++;
    int* temp = (int*) malloc((m+n) * sizeof(int));
    count++;
    int i = 0, j = 0, k = 0;
    count++;
    while (i < m && j < n) {
    	count++;
        if (nums1[i] >= nums2[j]) {
        	count++;
            temp[k] = nums1[i];
            count++;
            i++;
            count++;
        }
        else {
        	count++;
            temp[k] = nums2[j];
            count++;
            j++;
            count++;
        }
        k++;
        count++;
 }
    while (i < m) {
    	count++;
        temp[k] = nums1[i];
        count++;
        i++;
        count++;
        k++;
        count++;
    }
    while (j < n) {
        temp[k] = nums2[j];
        count++;
        j++;
        count++;
        k++;
        count++;
    }
    for (i = 0; i < m + n; i++) {
    	count++;
        nums1[i] = temp[i];
        count++;
    }
    free(temp);
    count++;
}
void mergeSort(int* nums, int low, int high) {
	count++;
    if (low < high) {
    	count++;
        int mid = low + (high - low) / 2;
        count++;
        mergeSort(nums, low, mid);
        count++;
        mergeSort(nums, mid + 1, high);
        count++;
        merge(nums + low, mid - low + 1, nums + mid + 1, high - mid);
        count++;
    }
}

int main() {
    int nums1[6] = {8, 7, 6};
    count++;
    int nums2[3] = {5, 4, 3};
    count++;
    int m = 3, n = 3;
    count++;
    mergeSort(nums1, 0, m - 1);
    count++;
    mergeSort(nums2, 0, n - 1);
    count++;
    merge(nums1, m, nums2, n);
     count++;
    printf("Merged array: ");
    count++;
    for (int i = 0; i < m + n; i++) {
    	count++;
        printf("%d ", nums1[i]);
        count++;
    }
    printf("\n");
    count++;
    printf("time complexity is %d ",count);
}
