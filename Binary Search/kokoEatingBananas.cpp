// LeetCode - Medium : 875. Koko Eating Bananas

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

long long getHours(vector<int> &piles,int guess){
    long long hours=0;
    for(int i=0;i<piles.size();i++){
        hours+=piles[i]/guess;

        if(piles[i]%guess!=0){
            hours++;
        }
    }
    return hours;
}

int minEatingSpeed(vector<int>&piles, int h){
    int low=1;
    int high=*max_element(piles.begin(),piles.end());

    int res=high;

    while (low<=high)
    {
        int guess=(low+high)/2;
        long long ans = getHours(piles,guess);

        if(ans>h){
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
    vector<int> piles={30,11,23,4,20};
    int h=5;

    int result=minEatingSpeed(piles,h);
    cout<<"Minimum bananas to be eaten in an hour such that all bananas would be finished in given time : "<<result;
}

// LeetCode Exact Question :

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4

// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23
 

// Constraints:

// 1 <= piles.length <= 104
// piles.length <= h <= 109
// 1 <= piles[i] <= 109