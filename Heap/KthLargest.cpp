#include<iostream>
using namespace std;
#include<vector>
#include<queue>

int KthLargest(vector<int> &nums,int k){
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }

    for(int i=k;i<nums.size();i++){
        if(nums[i]<=pq.top()){
            continue;
        }
        else{
            pq.pop();
            pq.push(nums[i]);
        }
    }

    return pq.top();
}

int main(){
    vector<int> nums={10,5,60,50,80,20};
    int k=3;

    int result=KthLargest(nums,k);
    cout<<"Kth Largest Element is : "<<result;
}