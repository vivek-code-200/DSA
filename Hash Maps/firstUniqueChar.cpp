// LeetCode - Easy : 387. First Unique Character in a String

#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>

int firstUniqueCharIndex(string s){
    unordered_map<char,int> f;

    for(int i=0;i<s.length();i++){
        f[s[i]]++;
    }

    for(int i=0;i<s.length();i++){
        if(f[s[i]]==1){
            return i;
        }
    }

    return -1;
}

int main(){
    string s="loveleetcode";

    int result = firstUniqueCharIndex(s);

    cout<<"First Unique Character Index is : "<<result;
}

// Exact LeetCode Question :

// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
 

// Example 1:

// Input: s = "leetcode"

// Output: 0

// Explanation:

// The character 'l' at index 0 is the first character that does not occur at any other index.


// Example 2:

// Input: s = "loveleetcode"

// Output: 2

// Example 3:

// Input: s = "aabb"

// Output: -1