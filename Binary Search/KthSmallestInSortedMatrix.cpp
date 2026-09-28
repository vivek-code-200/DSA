#include<iostream>
using namespace std;
#include<vector>

int findSmallerCount(vector<vector<int>> &matrix,int guess,int n,int m){
    int row=n-1;
    int col=0;
    int count=0;

    while (row>=0 and col<m)
    {
        if(matrix[row][col]<=guess){
            count+=row+1;
            col++;
        }
        else{
            row--;
        }
    }
    
    return count;
}

int KthSmallest(vector<vector<int>> &matrix,int k){
    int n=matrix.size();
    int m=matrix[0].size();
    int low=matrix[0][0];
    int high=matrix[n-1][m-1];
    int res=-1;

    while (low<=high)
    {
        int guess=(low+high)/2;
        int ans=findSmallerCount(matrix,guess,n,m);

        if(ans<k){
            low=guess+1;
        }
        else{
            res=guess;
            high=guess-1;
        }
    }
    
    return res;
}


int main(){
    vector<vector<int>> matrix={{1,5,7},{3,6,8},{4,9,11}};

    int result=KthSmallest(matrix,5);
    cout<<"Kth Smallest Element in Matrix : "<<result;
}