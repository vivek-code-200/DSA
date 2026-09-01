// LeetCode 167. Medium : Two Sum II - Input Array Is Sorted 
// Change : Returning number instead of index

#include <stdio.h>
#include <stdlib.h>

// If Array is not sorted
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int* twoSums(int *arr, int target, int size, int* returnSize)
{
    int i = 0;
    int j = size - 1;
    int* result = malloc(2 * sizeof(int));
    *returnSize=0;

    // If Array is not sorted
    qsort(arr, size, sizeof(int), compare);
    printf("Sorted array is : \t");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum > target)
        {
            j--;
            continue;
        }
        else if (sum < target)
        {
            i++;
            continue;
        }
        else if (sum == target)
        {
            result[0] = arr[i];
            result[1] = arr[j];
            *returnSize = 2;
            break;
        }
    }
    return result;
}

int main()
{
    int size;
    printf("Enter array size : ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));

    printf("Enter array elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Your array is : \t");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int returnSize;
    int* result = twoSums(arr, 15, size, &returnSize);
    if (returnSize == 2)
    {
        printf("\nMatch Found!\n");
        printf("Target numbers are : %d, %d", result[0], result[1]);
    }
    else if(returnSize==0)
    {
        printf("\nNo match found!");
    }
    return 0;
}


// Exact Leetcode Question :

// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

// Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.

// The tests are generated such that there is exactly one solution. You may not use the same element twice.

// Your solution must use only constant extra space.

 

// Example 1:

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
// Example 2:

// Input: numbers = [2,3,4], target = 6
// Output: [1,3]
// Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
// Example 3:

// Input: numbers = [-1,0], target = -1
// Output: [1,2]
// Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
