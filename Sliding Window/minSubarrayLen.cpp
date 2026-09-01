// LeetCode - Medium : 209. Minimum Size Subarray Sum

#include <iostream>
using namespace std;
#include <climits>
#include <algorithm>
#include <vector>

int minSubarrayLen(vector<int> &arr,int target){
    int low=0,high=0;
        int result=INT_MAX;
        int sum=0;

        while(high<arr.size()){
            sum=sum+arr[high];

            while(sum>=target){
                int len=high-low+1;
                result=min(result,len);
                sum=sum-arr[low];
                low++;
            }

            high++;
        }
        return result == INT_MAX ? 0 : result;       
}

int main(){
    vector<int> arr= {1,2,3,4};

    int result=minSubarrayLen(arr,11);
    cout<<"Result is : "<<result;
}

// Exact LeetCode Question :
// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0