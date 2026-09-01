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