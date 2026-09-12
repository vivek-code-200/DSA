// LeetCode - Easy : 1189. Maximum Number of Balloons

#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <unordered_map>
#include <climits>

int maxNumberOfBalloons(string s)
{
    int res = INT_MAX;
    unordered_map<char, int> have;
    unordered_map<char, int> need;
    need['b'] = 1;
    need['a'] = 1;
    need['l'] = 2;
    need['o'] = 2;
    need['n'] = 1;

    for (int i = 0; i < s.length(); i++)
    {
        have[s[i]]++;
    }

    for (auto i : need)
    {
        char c = i.first;
        int fhave = have[c];
        int fneed = need[c];

        if (fhave < fneed)
        {
            return 0;
        }

        int times = fhave / fneed;
        res = min(res, times);
    }

    return res;
}

int main()
{
    string s = "lloo";

    int result= maxNumberOfBalloons(s);
    cout<<"Maximum number of 'balloon' can be formed : "<<result;
}

// Exact LeetCode Question :

// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.

// Example 1:

// Input: text = "nlaebolko"
// Output: 1

// Example 2:

// Input: text = "loonbalxballpoon"
// Output: 2

// Example 3:

// Input: text = "leetcode"
// Output: 0