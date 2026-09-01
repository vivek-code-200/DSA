// LeetCode : Medium - 424. Longest Repeating Character Replacement

#include <iostream>
using namespace std;
#include <array>
#include <string>
#include <algorithm>
#include <climits>

int findMax(const array<int,256> &arr){
    int maximum=0;
    for(int i=0;i<256;i++){
        maximum=max(maximum,arr[i]);
    }
    return maximum;
}

int characterReplacement(string &s, int k){
    int low=0,high=0;
    int result=INT_MIN;
    array<int,256> freq{};
    int len,max_char,diff;

    for (high=0;high<s.length();high++){
        freq[s[high]]++;
        len=high-low +1;
        max_char=findMax(freq);
        diff=len-max_char;

        while(diff>k){
            freq[s[low]]--;
            low++;
            len=high-low+1;
            max_char=findMax(freq);
            diff=len-max_char;
        }

        int length=high-low+1;
        result = max(result,length);
    }

    return result;

}

int main(){
    string s="aabadrddd";
    int result = characterReplacement(s,1);

    cout<<"Result is : "<<result;
}

// LeetCode Exact Question :
 
// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.