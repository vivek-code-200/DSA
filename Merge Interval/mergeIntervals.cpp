#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<vector<int>> mergeIntervals(vector<vector<int>> &nums){
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    int start1 = nums[0][0];
    int end1 = nums[0][1];

    for(int i =1;i<nums.size();i++){
        int start2 = nums[i][0];
        int end2 = nums[i][1];

        if(end1>=start2){
            start1 = start1;
            end1 = max(end1,end2);
            continue;
        }
        else{
            result.push_back({start1,end1});
            start1 = start2;
            end1 = end2;
        }
    }
    result.push_back({start1,end1});
    return result;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{7,8},{8,16}};
    vector<vector<int>> mergedIntervals = mergeIntervals(intervals);

    cout<<"Merged Intervals are : \n";
    for(int i=0; i<mergedIntervals.size();i++){
        cout<<"["<<mergedIntervals[i][0]<<","<<mergedIntervals[i][1]<<"] ";
    }
}