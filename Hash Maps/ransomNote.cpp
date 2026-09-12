// LeetCode - Easy : 383. Ransom Note

#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>

bool canConstruct(string ransom, string magazine)
{
    unordered_map<char, int> need;
    unordered_map<char, int> have;

    for (int i = 0; i < ransom.length(); i++)
    {
        need[ransom[i]]++;
    }

    for (int i = 0; i < magazine.length(); i++)
    {
        have[magazine[i]]++;
    }

    for (auto i : need)
    {
        char c = i.first;
        int fneed = need[c];
        int fhave = have[c];

        if (fhave < fneed)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string ransom = "abcr";
    string magazine = "bbacdf";

    bool isMake = canConstruct(ransom,magazine);

    cout<<"Ransom Note can be constructed by using Magazine : "<<isMake;
}

// Exact LeetCode Question :

// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false

// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false

// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true