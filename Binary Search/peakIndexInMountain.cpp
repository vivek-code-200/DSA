// LeetCode - Medium : 852. Peak Index in a Mountain Array

#include<iostream>
using namespace std;
#include<vector>

int peakIndexInMountain(vector<int> &nums){
    int low=0;
    int high=nums.size()-1;
    int res=-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(nums[mid]<nums[mid+1]){
            low=mid+1;
        }
        else{
            res=mid;
            high=mid-1;
        }
    }

    return res;
}

int main(){
    vector<int> arr={5,6,8,20,60,70,50,40,20};

    int result = peakIndexInMountain(arr);

    if(result==-1){
        cout<<"No such peak found!";
    }
    else{
        cout<<"Peak Index of Mountain is : "<<result;
    }
}

// Exact LeetCode Question:

// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

// Example 1:

// Input: arr = [0,1,0]

// Output: 1


// Example 2:

// Input: arr = [0,2,1,0]

// Output: 1


// Example 3:

// Input: arr = [0,10,5,2]

// Output: 1


// Constraints:

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.