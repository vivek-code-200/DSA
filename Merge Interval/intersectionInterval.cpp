// LeetCode - Medium : 986. Interval List Intersections

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<vector<int>> intersectionInterval(vector<vector<int>> &a, vector<vector<int>> &b){
    vector<vector<int>> res;
    int i=0,j=0;

    while (i<a.size() and j<b.size())
    {
        int start1 = a[i][0];
        int end1 = a[i][1];

        int start2 = b[j][0];
        int end2 = b[j][1];

        if(start1<=start2){
            if(end1>=start2){
                int s = max(start1,start2);
                int e = min(end1,end2);
                res.push_back({s,e});
            }
        }
        else{
            if(end2>=start1){
                int s=max(start1,start2);
                int e=min(end1,end2);
                res.push_back({s,e});
            }
        }

        if(end1<=end2){
            i++;
        }else{
            j++;
        }
    }

    return res;
    
}

int main(){
    vector<vector<int>> a = {{1,5},{8,10},{13,24},{25,28}};
    vector<vector<int>> b = {{2,4},{10,12},{25,28},{30,32}};
    vector<vector<int>> intersection = intersectionInterval(a,b);

    cout<<"Intersection Intervals of a and b are : \n";
    for(int i=0; i<intersection.size();i++){
        cout<<"["<<intersection[i][0]<<","<<intersection[i][1]<<"] ";
    }
}

// Exact LeetCode Question : 

// You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

// Return the intersection of these two interval lists.

// A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

// The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].
 

// Example 1:

// Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
// Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

// Example 2:

// Input: firstList = [[1,3],[5,9]], secondList = []
// Output: []