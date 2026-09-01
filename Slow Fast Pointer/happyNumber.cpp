// LeetCode - Easy : 202. Happy Number

#include <iostream>
using namespace std;

int sumSquaredDigits(int n){
    int sum=0;
    while(n>0){
        int d=n%10;
        n=n/10;
        sum=sum+d*d;
    }
    return sum;
}

bool happyNumber(int n){
    int slow=n;
    int fast=n;

    while(fast!=1){
        slow=sumSquaredDigits(slow);
        fast=sumSquaredDigits(fast);
        fast=sumSquaredDigits(fast);

        if(slow==fast and slow!=1){
            return false;
        }
    }
    return true;
}

int main(){
    int n=19;

    bool check = happyNumber(n);

    if(check==true){
        cout<<"Yes , It is Happy Number.";
    }
    else{
        cout<<"No, It's not a Happy Number ";
    }
}

// Exact LeetCode Question :

// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

 

// Example 1:

// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
// Example 2:

// Input: n = 2
// Output: false