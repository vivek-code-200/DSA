// LeetCode : Medium - 16. 3Sum Closest

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <array>
#include <climits>

int tripleSumZero(vector<int> &arr, int &target)
{
    int size = arr.size();
    sort(arr.begin(), arr.end());

    int max_diff = INT_MAX;
    int result_sum;

    for (int i = 0; i < size - 2; i++)
    {
        if (i > 0 and arr[i] == arr[i - 1])
        {
            continue;
        }

        int left = i + 1;
        int right = size - 1;

        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];
            int diff = abs(sum - target);
            if (diff < max_diff)
            {
                max_diff = diff;
                result_sum = sum;
            }

            if (sum == target)
            {
                return result_sum;   
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return result_sum;
}

int main()
{
    vector<int> arr = {-1,2,1,-4};
    int target = 1;
    int result = tripleSumZero(arr, target);

    cout<<"Closest sum is :"<<result;
}

// LeetCode Exact Question : 

// Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).