// LeetCode : Medium - 75. Sort Colors

#include <iostream>
using namespace std;
#include <vector>

vector<int> dutchFlag(vector<int> &nums){
    int low =0,mid=0,high=nums.size()-1;

    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            mid++;
            low++;
        }

        else if(nums[mid]==1){
            mid++;
        }

        else if(nums[mid]==2){
            swap(nums[mid],nums[high]);
            high--;
        }
    }
    return nums;
}

int main()
{
    vector<int> arr = {2,0,1};
    vector<int> result=dutchFlag(arr);
 
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}

// LeetCode Exact question :

// You are given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]

// Output: [0,0,1,1,2,2]

// Explanation:

// The array has two 0s, two 1s, and two 2s. Sorting them in-place places all 0s first, then all 1s, then all 2s.

// Example 2:

// Input: nums = [2,0,1]

// Output: [0,1,2]

// Explanation:

// The array has one each of 0, 1, and 2, arranged in-place in the order 0, 1, 2.