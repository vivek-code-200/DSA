#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<queue>

struct cmd
{
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        if(a.first!=b.first){
            return a.first>b.first;
        }
        return a.second>b.second;
    }
};

vector<int> topKFrequentElements(vector<int> &nums,int k){
    unordered_map<int,int> f;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmd> pq;
    vector<int> res;

    for(int i=0;i<nums.size();i++){
        f[nums[i]]++;
    }

    for(auto i:f){
        int element=i.first;
        int freq=i.second;
        pair<int,int> curr={freq,element};

        if(pq.size()<k){
            pq.push(curr);
            continue;
        }
        if(curr.first<pq.top().first){
            continue;
        }
        pq.pop();
        pq.push(curr);
    }

    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}


int main(){
    vector<int> nums={1,22,5,9,23};
    int k=2;

    vector<int> res=topKFrequentElements(nums,k);

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<",";
    }
}