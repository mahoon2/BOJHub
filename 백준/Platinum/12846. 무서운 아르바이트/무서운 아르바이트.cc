#include <iostream>
#include <stack>

#define MAX_N 100009

using namespace std;

int n;
int inp[MAX_N];
stack<int> st;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    inp[0] = 0;
    for(int i=1; i<=n; i++)
    {
        cin >> inp[i];
    }
    inp[n+1] = 0;

    int ret = -1;
    st.push(0);
    for(int i=1; i<=n+1; i++)
    {
        int idx = st.top();
        if(inp[idx] > inp[i])
        {
            while(inp[idx] > inp[i])
            {
                st.pop();
                if(st.empty()) break;
                ret = max(ret, (i-st.top()-1)*inp[idx]);
                idx = st.top();
            }
        }
        else if(inp[idx] == inp[i])
        {
            st.pop();
        }
        st.push(i);
    }

    cout << ret << '\n';

    return 0;
}