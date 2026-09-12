// GeeksForGeeks - Medium

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int tripletSumSmaller(vector<int> &nums, int target)
{
    int size = nums.size();
    sort(nums.begin(), nums.end());
    int result=0;

    for (int i = 0; i < size - 2; i++)
    {
        int left = i + 1;
        int right = size - 1;

        while(left<right){

            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum < target)
            {
                result = result + (right - left);
                left++;
            }
            if(sum>=target){
                right--;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {2, 5, 6, 1, 4, 7};

    int result = tripletSumSmaller(arr,5);

    cout<<"Result is : "<<result;
}

// Exact GeeksForGeeks Question :

// Given an array arr[] of distinct integers and an integer sum, count the number of unique triplets of elements whose sum is strictly less than sum. A triplet is identified only by the three elements it contains, so different permutations of the same three elements are counted as one triplet.

// Examples :

// Input: sum = 2, arr[] = [-2, 0, 1, 3]
// Output:  2
// Explanation: Triplets with sum less than 2 are (-2, 0, 1) and (-2, 0, 3). 

// Input: sum = 12, arr[] = [5, 1, 3, 4, 7]
// Output: 4
// Explanation: Triplets with sum less than 12 are (1, 3, 4), (5, 1, 3), (1, 3, 7) and (5, 1, 4).