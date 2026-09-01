// LeetCode : Easy - 977. Squares of a Sorted Array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquare(vector<int> &arr)
{
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            neg.push_back(arr[i]);
        }
        else
        {
            pos.push_back(arr[i]);
        }
    }

    if (neg.size() == 0)
    {
        for (int i = 0; i < pos.size(); i++)
        {
            pos[i] = pos[i] * pos[i];
        }
        return pos;
    }

    if (pos.size() == 0)
    {
        for (int i = 0; i < neg.size(); i++)
        {
            neg[i] = neg[i] * neg[i];
        }
        reverse(neg.begin(), neg.end());
        return neg;
    }

    int i = 0, j = 0;
    int k = 0;
    int n = neg.size();
    int m = pos.size();
    vector<int> result(n+m);

    for (int i = 0; i < n; i++)
    {
        neg[i] = neg[i] * neg[i];
    }
    reverse(neg.begin(), neg.end());

    for (int i = 0; i < m; i++)
    {
        pos[i] = pos[i] * pos[i];
    }

    while (i < n and j < m)
    {
        if (neg[i] <= pos[j])
        {
            result[k] = neg[i];
            k++;
            i++;
        }
        else
        {
            result[k] = pos[j];
            k++;
            j++;
        }
    }

    while (i < n)
    {
        result[k]=neg[i];
        i++;
        k++;
    }

    while (j < m)
    {
        result[k]=pos[j];
        j++;
        k++;
    }

    return result;
}

int main()
{
    vector<int> arr={-4,-1,0,2,5,7};

    vector<int> result=sortedSquare(arr);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}


// Exact LeetCode Question :
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

// Example 2:

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]