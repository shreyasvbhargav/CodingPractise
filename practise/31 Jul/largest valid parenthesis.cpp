#include<iostream>
#include<string>
#include<stack>
using namespace std;

#if 0
int longestValidParentheses(string s) {
    stack<char> st;
    int count=0;
    if(s.empty())
        return 0;
    for(int i=0; i<s.length(); i++)
    {
        if(st.empty())
            st.push(s[i]);
        else if(s[i]==')' && st.top()=='('){
            st.pop();
            count++;
        }
        else
            st.push(s[i]);
    }
    return count*2;
}
#endif

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1); // push -1 as initial index to start from
    int maxLength = 0;
    
    for(int i=0; i<s.size(); i++) {
        // if current character is '(', push its index
        if(s[i] == '(') {
            st.push(i);
        }
        else { 
            // if current character is ')', pop the top
            if(!st.empty())
                st.pop();
            // if stack is not empty, update the maxLength 
            // by the difference of current index and index at the top of the stack
            if(!st.empty()) {
                maxLength = max(maxLength, i - st.top());
            }
            else {
                // if stack is empty, push the current index
                st.push(i);
            }
        }
    }
    
    return maxLength;
}

int main()
{
    string s="))())";
    cout<<longestValidParentheses(s);
    // s=")()())";
    // cout<<longestValidParentheses(s);
}