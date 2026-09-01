#include <iostream>
using namespace std;
#include <array>
#include <string>
#include <climits>

bool check(array<int, 256> &have, array<int, 256> &need)
{
    for (int i = 0; i < 256; i++)
    {
        if (have[i] < need[i])
        {
            return false;
        }
    }
    return true;
}

string minimumWindowSubstring(string &s, string &t)
{
    array<int, 256> have = {};
    array<int, 256> need = {};

    for (int i = 0; i < t.size(); i++)
    {
        need[t[i]]++;
    }

    int low = 0, high = 0, res = INT_MAX, start = 0;

    for (high = 0; high < s.size(); high++)
    {
        have[s[high]]++;
        while(check(have,need)){
            int len=high-low+1;
            if(len<res){
                res=len;
                start=low;
            }
            have[s[low]]--;
            low++;
        }
    }

    if(res==INT_MAX){
        return "";
    }

    return s.substr(start,res);
}

int main()
{
    string s = "a";
    string t = "aa";

    string minimumSubstring=minimumWindowSubstring(s,t);

    cout<<"Minimum Substring is : "<<minimumSubstring;
}