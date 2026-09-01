// GeeksForGeeks : Easy - Max Sum Subarray of size K

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <climits>

int maximumSum(vector<int> &nums, int k)
{
    int low = 0, high = k - 1;
    int result = INT_MIN;
    int sum=0;
    for (int i = low; i <= high; i++)
    {
        sum=sum+nums[i];
    }

    while(high<nums.size()){
        result=max(result,sum);
        low++;
        high++;
        sum=sum-nums[low-1]+nums[high];
    }

    return result;
}

int main()
{
    vector<int> arr = {100, 200, 300, 400};

    int result = maximumSum(arr,2);
    cout<<"Result is : "<<result;
}

// Exact GeeksForGeeks Question :

// Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

// Note: A subarray is a contiguous part of any given array.

// Examples:

// Input: arr[] = [100, 200, 300, 400], k = 2
// Output: 700
// Explanation: arr2 + arr3 = 700, which is maximum.
// Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
// Output: 39
// Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.
// Input: arr[] = [100, 200, 300, 400], k = 1
// Output: 400
// Explanation: arr3 = 400, which is maximum.