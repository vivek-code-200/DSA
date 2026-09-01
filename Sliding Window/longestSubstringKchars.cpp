// GeeksForGeeks : Medium

#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>
#include <climits>
#include <algorithm>

int longestSubstring(string &s,int k){
    int length=s.length();
    int low=0,high=0;
    int result=INT_MIN;
    unordered_map<char,int> f;

    for(high=0;high<length;high++){
        f[s[high]]++;

        if(f.size()>k){
            f[s[low]]--;
            if(f[s[low]]==0){
                f.erase(s[low]);
            }
            low++;
        }

        if(f.size()==k){
            int len=high-low+1;
            result=max(result,len);
        }
    }

    return result==INT_MIN ? 0 : result;
}

int main(){
    string s="abaadaa";

    int result=longestSubstring(s,10);
    cout<<"Result is : "<<result;

}

// GeeksForGeeks Exact Question :

// You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

// Note : If no such substring exists, return -1. 

// Examples:

// Input: s = "aabacbebebe", k = 3
// Output: 7
// Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.

// Input: s = "aaaa", k = 2
// Output: -1
// Explanation: There's no substring with 2 distinct characters.

// Input: s = "aabaaab", k = 2
// Output: 7
// Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.