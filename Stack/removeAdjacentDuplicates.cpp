// LeetCode - Easy : 1047. Remove All Adjacent Duplicates In String

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string removeAdjacentDuplicates(string s){
    string res;
    stack<char> st;

    for(int i=0;i<s.length();i++){
        if(st.empty()){
            st.push(s[i]);
            continue;
        }
        if(st.top()==s[i]){
            st.pop();
            continue;
        }
        st.push(s[i]);
    }

    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    string s="abbaccab";

    string result =removeAdjacentDuplicates(s);
    cout<<"Result : "<<result;
}

// Exact LeetCode Question :

// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

// Example 1:

// Input: s = "abbaca"
// Output: "ca"
// Explanation: 
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

// Example 2:

// Input: s = "azxxzy"
// Output: "ay"