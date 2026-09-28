#include<iostream>
using namespace std;
#include<vector>

vector<int> findfirstAndLastOccurence(vector<int> &nums, int target){
    int first=-1;
        int last=-1;

        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high=mid-1;
            }
        }

        low=0;
        high=nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid]==target){
                last = mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return {first,last};
}

int main(){
    vector<int> nums={1,2,8,8,10,11};

    vector<int> result=findfirstAndLastOccurence(nums,8);
    cout<<"First and Last Element Occurred at Index : ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<", ";
    }
}