// LeetCode 26. Easy : Remove Duplicates from Sorted Array

#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *arr, int size)
{
    int i=0,j=1,k=1;
    while (j < size)
    {
        if (arr[j] == arr[j - 1])
        {
            j++;
            continue;
        }
        else
        {
            arr[i + 1] = arr[j];
            i++;
            j++;
            k++;
        }
    }
    return k;
}

int main()
{
    int arr[] = {1, 1, 2, 3, 3,4,5,5,9};
    int size = sizeof(arr) / sizeof(int);

    int result=removeDuplicates(arr, size);
    printf("Result is : %d", result);
}