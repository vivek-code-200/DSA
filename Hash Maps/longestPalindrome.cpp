#include<iostream>
using namespace std;
#include<string>
#include<unordered_map>

int longestPalindrome (string s){
    unordered_map<char,int> f;
    int res=0;
    bool hasOdd=false;

    for(int i=0;i<s.length();i++){
        f[s[i]]++;
    }

    for(auto i :f){
        int count =i.second;
        if(count%2==0){
            res+=count;
        }
        else {
            res+=count-1;
            hasOdd=true;
        }
    }

    if(hasOdd){
        res+=1;
    }

    return res;
}

int main(){
    string s="ccccdd";
    int result = longestPalindrome(s);
    cout<<"Longest Palindrome : "<<result;
}