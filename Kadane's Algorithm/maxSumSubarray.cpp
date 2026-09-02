// LeetCode - Medium : 53. Maximum Subarray

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int maximumSubarraySum(vector<int> &nums){
    int bestEnding = nums[0];
    int result = nums[0];

    for(int i=1;i<nums.size();i++){
        int v1 = bestEnding + nums[i];
        int v2 = nums[i];
        bestEnding = max(v1,v2);
        result = max(result,bestEnding);
    }

    return result;
}

int main(){
    vector<int> nums ={1,5,-1,2,-3};
    int maxSumSubarray = maximumSubarraySum(nums);
    cout<<"Maximum Sum of Subarray : "<<maxSumSubarray;
}

// Exact LeetCode Question :

// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.