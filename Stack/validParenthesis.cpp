// LeetCode - Easy : 20. Valid Parentheses

#include <iostream>
using namespace std;
#include <string>
#include <stack>
#include <algorithm>

bool isValidParenthesis(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
        {
            st.push(s[i]);
            continue;
        }

        if (st.empty())
        {
            return false;
        }

        if (s[i] == ')' and st.top() == '(')
        {
            st.pop();
            continue;
        }
        if (s[i] == '}' and st.top() == '{')
        {
            st.pop();
            continue;
        }
        if (s[i] == ']' and st.top() == '[')
        {
            st.pop();
            continue;
        }
        return false;
    }
    if (!st.empty())
    {
        return false;
    }
    return true;
}

int main()
{
    string parenthesis = "{}{({[]})}{)}";

    bool isValid = isValidParenthesis(parenthesis);
    cout << "Is Parenthesis valid : " << isValid;
}

// Exact LeetCode Question :

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"

// Output: true

// Example 2:

// Input: s = "()[]{}"

// Output: true

// Example 3:

// Input: s = "(]"

// Output: false

// Example 4:

// Input: s = "([])"

// Output: true

// Example 5:

// Input: s = "([)]"

// Output: false