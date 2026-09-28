// GeeksForGeeks - Medium : Aggressive Cows

#include<iostream>
using namespace std;
#include<vector>

int checkGuess(vector<int> &stalls, int n, int cows,int guess){
    int cow=1;
    int pos=stalls[0];

    for(int i=1;i<n;i++){
        int dist=stalls[i]-pos;

        if(dist<guess){
            continue;
        }
        else{
            cow++;
            pos=stalls[i];
        }
    }

    if(cow>=cows){
        return true;
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int cows){
    int n=stalls.size();

    int low=0;
    int high=stalls[n-1]-stalls[0];
    int res=0;

    while (low<=high)
    {
        int guess=(low+high)/2;

        if(checkGuess(stalls,n,cows,guess)){
            res=guess;
            low=guess+1;
        }
        else{
            high=guess-1;
        }
    }

    return res;   
}

int main(){
    vector<int> stalls={1,2,4,8,9};

    int result = aggressiveCows(stalls,3);

    cout<<"Minimum Distance required to put K Cows in Stalls : "<<result;
}

// Exact GeeksForGeeks Question :

// Given an integer array arr[], which denotes the positions of stalls. All the positions are distinct. There are k aggressive cows.

// Assign the cows to the stalls such that the minimum distance between any two cows is maximized.

// Examples:

// Input: arr[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at arr[0], the second at arr[2], and the third at arr[3]. The minimum distance between any two cows is 3 (between arr[0] and arr[2]), which is the maximum possible among all valid arrangements.

// Input: arr[] = [10, 1, 2, 7, 5], k = 3
// Output: 4
// Explanation: The first cow can be placed at arr[0], the second at arr[1], and the third at arr[4]. In this arrangement, the minimum distance between any two cows is 4 (between arr[1] and arr[4]), which is the maximum possible among all valid arrangements.

// Constraints:

// arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 108
// 2 ≤ k ≤ arr.size()