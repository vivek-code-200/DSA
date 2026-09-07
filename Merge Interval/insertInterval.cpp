#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<vector<int>> insertInterval(vector<vector<int>> &nums, vector<int> &interval){
    sort(nums.begin(),nums.end());

    vector<vector<int>> result;
    int insert = false;
    for(int i=0;i<nums.size();i++){
        int start = nums[i][0];
        if(insert==false and start>interval[0]){
            result.push_back(interval);
            insert = true;
        }
        result.push_back(nums[i]);
    }
    if(insert==false){
        result.push_back(interval);
    }

    vector<vector<int>> res;
    int start1=result[0][0];
    int end1=result[0][1];

    for(int i=1;i<result.size();i++){
        int start2=result[i][0];
        int end2=result[i][1];

        if(end1>=start2){
            start1=start1;
            end1=max(end1,end2);
            continue;
        }
        else{
            res.push_back({start1,end1});
            start1=start2;
            end1=end2;
        }
    }
    res.push_back({start1,end1});
    return res;
}

int main(){
    vector<vector<int>> intervals = {{1,2},{3,5},{6,8},{8,10},{12,15}};
    vector<int> interval = {4,7};

    vector<vector<int>> insertedMergedIntervals = insertInterval(intervals,interval);

    cout<<"Merged Intervals after insertion are : \n";
    for(int i=0; i<insertedMergedIntervals.size();i++){
        cout<<"["<<insertedMergedIntervals[i][0]<<","<<insertedMergedIntervals[i][1]<<"] ";
    }
}