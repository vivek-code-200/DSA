#include <iostream>
using namespace std;
#include <vector>

int searchInRoatedSortedArray(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }

        // Part 1
        if (arr[mid] > arr[n - 1])
        {
            if (arr[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                if (arr[n - 1] < target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            continue;
        }

        // Part 2
        if(arr[mid]>target){
            high=mid-1;
        }
        else{
            if(arr[n-1]>target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {50, 60, 70, 5, 10, 20, 30, 40};

    int result = searchInRoatedSortedArray(arr, 10);
    if (result != -1)
    {
        cout << "Element Found at Index : " << result;
    }
    else
    {
        cout << "Element Not Found!";
    }
}