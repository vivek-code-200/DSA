#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k = 0;
        vector<int> result(m + n);
        while (i < m and j < n) {
            if (nums1[i] <= nums2[j]) {
                result[k] = nums1[i];
                k++;
                i++;
            } else {
                result[k] = nums2[j];
                k++;
                j++;
            }
        }
        while (i < m) {
            result[k] = nums1[i];
            k++;
            i++;
        }
        while (j < n) {
            result[k] = nums2[j];
            k++;
            j++;
        }
        return result;
    }

int main()
{
    vector<int> arr1={1,2,3,0,0,0};
    vector<int> arr2={2,5,6};
    int m=3,n=3;

    vector<int> result=merge(arr1,m,arr2,n);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}