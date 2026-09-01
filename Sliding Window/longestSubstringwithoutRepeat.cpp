// LeetCode : Medium - 3. Longest Substring Without Repeating Characters

#include <iostream>
using namespace std;
#include <climits>
#include <algorithm>
#include <string>
#include <unordered_map>

int longestSubstringWithoutRepeat(string s){
    int length = s.length();
    int low=0, high=0;
    int result = INT_MIN;
    int k;
     
    unordered_map<char,int> f;

    for(high=0;high<length;high++){
        f[s[high]]++;
        k=high-low+1;

        while(f.size()<k){
            f[s[low]]--;
            if(f[s[low]]==0){
                f.erase(s[low]);
            }
            low++;
            k=high-low+1;
        }

        int len=high-low+1;
        result=max(result,len);
    }

    return result;
}

int main(){
    string s ="abaacdf";

    int result = longestSubstringWithoutRepeat(s);
    cout<<"Result is : "<<result;

}

// LeetCode Exact Question :- 

// Given a string s, find the length of the longest substring without duplicate characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.