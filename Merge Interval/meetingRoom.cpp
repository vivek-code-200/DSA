#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int minMeetingRoom(vector<int> &start, vector<int> &end){
    int n = start.size();
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());

    int i=0,j=0,rooms=0,res=0;

    while(i<n and j<n){
        if(start[i]<end[j]){
            rooms++;
            res=max(res,rooms);
            i++;
        }
        else{
            rooms--;
            j++;
        }
    }

    return res;
}

int main(){
    vector<int> start = {2,5,4,3};
    vector<int> end = {3,7,8,9};

    int minRoomRequired = minMeetingRoom(start,end);

    cout<<"Minimum room required for meetings is : "<<minRoomRequired;
}