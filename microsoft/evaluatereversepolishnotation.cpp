// Leetcode link- https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/868410962/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        long long int ans = 0;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                long long int a = st.top();
                st.pop();
                long long int b = st.top();
                st.pop();
                if (tokens[i] == "+")
                {
                    ans = a + b;
                }
                else if (tokens[i] == "-")
                {
                    ans = b - a;
                }
                else if (tokens[i] == "*")
                {
                    ans = a * b;
                }
                else if (tokens[i] == "/")
                {
                    ans = b / a;
                }
                st.push(ans);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};