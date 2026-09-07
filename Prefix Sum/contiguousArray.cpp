// LeetCode - Medium : 525. Contiguous Array

#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

int contiguousArray(vector<int> &nums){
    int zero=0, one=0;
    unordered_map<int,int> f;
    int res = 0;

    for(int i=0; i<nums.size(); i++){
        if(nums[i]==0){
            zero++;
        }else{
            one++;
        }
        int diff= zero - one;
        if(diff==0){
            res=max(res,i+1);
            continue;
        }
        if(f.find(diff)==f.end()){
            f[diff]=i;
        }
        else{
            int index = f[diff];
            int len = i-index;
            res=max(res,len);
        }
    }

    return res;

}

int main(){
    vector<int> nums={0,1,1,1,1,1,0,0,0};
    int result = contiguousArray(nums);
    cout<<"Size of a contiguous array : "<<result;
}

// Exact LeetCode Question :

// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

// Example 1:

// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

// Example 2:

// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

// Example 3:

// Input: nums = [0,1,1,1,1,1,0,0,0]
// Output: 6
// Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.