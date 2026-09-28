#include<iostream>
using namespace std;
#include<algorithm>

int findSmaller(int m,int n,int guess){
    int count=0;

    for(int i=1;i<=m;i++){
        count+=min(n,guess/i);
    }

    return count;
}

int KthSmallest(int m,int n, int k){
    int low=1;
    int high=m*n;
    int res=low;

    while (low<=high)
    {
        int guess=low+(high-low)/2;
        int ans=findSmaller(m,n,guess);

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
    int m=3,n=3,k=5;

    int result = KthSmallest(m,n,k);

    cout<<"Kth Smallest Number in Multiplication Matrix : "<<result;
}