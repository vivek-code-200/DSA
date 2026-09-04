// LeetCode - Medium : 560. Subarray Sum Equals K

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

int subarraySumK(vector<int> &nums,int k){
    unordered_map<int,int> f;
    f[0]=1;
    int sum =0, res=0;

    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        int ques = sum - k;
        res+=f[ques];
        f[sum]++;
    }

    return res;
}

int main(){
    vector<int> nums={1,1,1};

    int result = subarraySumK(nums,2);

    cout<<"Total Subarray of Sum 2 : "<<result;
}

// Exact LeetCode Question :

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.
 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2