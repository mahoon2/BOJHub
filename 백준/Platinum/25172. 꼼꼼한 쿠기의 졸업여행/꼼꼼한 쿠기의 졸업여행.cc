#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

#define MAX_N 200001

using namespace std;

vector<int> adj[MAX_N];
stack<int> st;
bool isIdeal[MAX_N];
bool isActive[MAX_N];
int parent[MAX_N];
int size_num[MAX_N];
int n;

int find_parent(int x)
{
    if(parent[x] == x) return x;
    else return parent[x] = find_parent(parent[x]);
}

int merge(int x, int y)
{
    // y의 부모로 x를 설정
    int px = find_parent(x);
    int py = find_parent(y);

    if(px == py) return 0;

    parent[py] = px;
    size_num[px] += size_num[py];
    size_num[py] = 0;

    return size_num[px];
}

void solve()
{
    int idx = 1;
    isIdeal[idx] = true;
    isActive[st.top()] = true;
    st.pop();

    while(!st.empty())
    {
        idx++;
        int here = st.top();
        st.pop();
        isActive[here] = true;

        int cnt = 0;
        for(int there: adj[here])
        {
            if(isActive[there])
            {
                cnt = max(cnt, merge(there, here));
            }
        }
        if(cnt == idx) isIdeal[idx] = true;
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m;

    int from, to;
    for(int i=0; i<m; i++)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int temp;
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        st.push(temp);
        parent[i+1] = i+1;
        size_num[i+1] = 1;
    }

    memset(isIdeal, false, sizeof(isIdeal));
    memset(isActive, false, sizeof(isActive));
    solve();
    for(int i=n; i>=0; i--)
    {
        if(isIdeal[i]) cout << "CONNECT" << '\n';
        else cout << "DISCONNECT" << '\n';
    }

    return 0;
}