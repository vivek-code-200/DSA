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