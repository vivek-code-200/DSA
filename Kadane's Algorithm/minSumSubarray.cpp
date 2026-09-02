// GeeksForGeeks - Medium : Minimum Sum Subarray

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int minimumSumSubarray(vector<int> &arr){
    int bestEnding = arr[0];
    int result = arr[0];

    for(int i=1;i<arr.size();i++){
        int v1=bestEnding+arr[i];
        int v2=arr[i];
        bestEnding=min(v1,v2);
        result=min(result,bestEnding);
    }

    return result;
}

int main(){
    vector<int> arr={5,-1,2,3,-5};

    int minimumSum = minimumSumSubarray(arr);

    cout<<"Minimum sum of Subarray : "<<minimumSum;
}

// Exact GeeksForGeeks Question :

// Given an array arr[], find the sub-array containing at least one number which has the minimum sum and return its sum.

// Examples :

// Input: arr[] = [3,-4, 2,-3,-1, 7,-5]
// Output: -6
// Explanation: The subarray is [-4,2,-3,-1] = -6

// Input: arr[] = [2, 6, 8, 1, 4]
// Output: 1
// Explanation: The subarray is [1] = 1