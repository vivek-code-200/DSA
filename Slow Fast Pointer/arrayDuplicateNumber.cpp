// LeetCode - Medium : 287. Find the Duplicate Number

#include <iostream>
using namespace std;
#include <vector>

int duplicateNumber(vector<int> &nums){
    int slow=0,fast=0;

    while(true){
        slow=nums[slow];
        fast=nums[fast];
        fast=nums[fast];
        if(slow==fast){
            slow=0;
            while(slow!=fast){
                slow=nums[slow];
                fast=nums[fast];
            }
            return slow;
        }
    }

    return -1;
}

int main(){
    vector<int> nums={3,3,3,3,3};

    int repeatedNumber=duplicateNumber(nums);
    if(repeatedNumber!=-1){
        cout<<"Duplicate number is : "<<repeatedNumber;
    }
    else{
        cout<<"No Duplicate found!";
    }
}

// Exact LeetCode Question :

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and using only constant extra space.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
// Example 3:

// Input: nums = [3,3,3,3,3]
// Output: 3