// LeetCode - Medium : 15. 3Sum

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <array>

vector<array<int, 3>> tripleSumZero(vector<int> &arr)
{
    int size = arr.size();
    sort(arr.begin(), arr.end());
    printf("Sorted array is : \t");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    vector<array<int, 3>> result;

    for (int i = 0; i < size - 2; i++)
    {
        if (i > 0 and arr[i] == arr[i - 1])
        {
            continue;
        }

        int left = i + 1;
        int right = size - 1;
        int s = -1 * arr[i];

        while (left < right)
        {
            int sum = arr[left] + arr[right];
            if (sum == s)
            {
                result.push_back({arr[i], arr[left], arr[right]});
                left++;
                right--;
                while (left < size and arr[left] == arr[left - 1])
                {
                    left++;
                }
                while (right >= 0 and arr[right] == arr[right + 1])
                {
                    right--;
                }
            }
            else if (sum < s)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {0, -1, 2, -1, 1, 4};
    vector<array<int, 3>> result = tripleSumZero(arr);

    // Method to Print vector array ,like 1 2 3 nextLine 4 5 6 :-

    // for(auto triplet : result){
    //     for(int x:triplet){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }

    // Another method to print vector array ,like {{1,2,3},{3,4,5}} :-

    cout << "{";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < 3; j++)
        {
            cout << result[i][j];
            if (j < 2)
            {
                cout << ",";
            }
        }
        cout << "}";
        if (i < result.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "}";
}

// Exact LeetCode Question :

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.

// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.