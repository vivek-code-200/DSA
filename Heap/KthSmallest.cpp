#include<iostream>
using namespace std;
#include<queue>

int KthSmallest(vector<int>&nums, int k){
    priority_queue<int> pq;

    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }

    for(int i=k;i<nums.size();i++){
        if(nums[i]>=pq.top()){
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
    vector<int> nums={10,20,5,204,1,60};
    int k=3;

    int result = KthSmallest(nums,k);
    cout<<"Kth Smallest Element is : "<<result;
}