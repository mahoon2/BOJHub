#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> st;
    
    for(auto& c: s)
    {
        if(c == '(') st.push(1);
        else if(st.empty())
        {
            answer = false;
            break;
        }
        else
        {
            st.pop();
        }
    }
    
    if(!st.empty()) answer = false;

    return answer;
}