// LeetCode - Medium : 739. Daily Temperatures

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

vector<int> dailyTemperatures(vector<int> &nums){
    int n=nums.size();
    vector<int> res(n);
    stack<int> st;

    res[n-1]=0;
    st.push(n-1);

    for(int i=n-2; i>=0; i--){
        while(!st.empty() and nums[st.top()]<=nums[i]){
            st.pop();
        }
        if(st.empty()){
            res[i]=0;
        }
        else{
            res[i]=st.top()-i;
        }
        st.push(i);
    }

    return res;
}

int main(){
    vector<int> nums={73,74,75,71,69,72,76,73};

    vector<int> result = dailyTemperatures(nums);

    cout<<"Result is : ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<", ";
    }
}

// Exact LeetCode Question :

// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]

// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]