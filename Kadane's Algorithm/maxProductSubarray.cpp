// LeetCode - Medium : 152. Maximum Product Subarray

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int maxProductSubarray(vector<int> &nums){
    int minBestEnding = nums[0];
    int maxBestEnding = nums[0];
    int result = nums[0];

    for(int i=1;i<nums.size();i++){
        int v1 = nums[i];
        int v2 = minBestEnding * nums[i];
        int v3 = maxBestEnding * nums[i];

        minBestEnding = min(v1, min(v2,v3));
        maxBestEnding = max(v1, max(v2,v3));
        result = max(result, max(minBestEnding,maxBestEnding));
    }

    return result;
}

int main(){
    vector<int> nums={-1,2,3,-2,-1,2,5};

    int maxProduct = maxProductSubarray(nums);

    cout<<"Maximum Product of Subarray : "<<maxProduct;
}


// Exact LeetCode Question :

// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// Note that the product of an array with a single element is the value of that element.

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.