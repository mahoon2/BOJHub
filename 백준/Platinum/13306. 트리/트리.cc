#include <iostream>
#include <stack>

#define MAX_N 200001

using namespace std;

int parent[MAX_N];
int adj[MAX_N];
int n, q;
bool ret[MAX_N];

stack< pair<int,int> > st;

int find_parent(int x)
{
    if(parent[x] == x) return x;
    else return parent[x] = find_parent(parent[x]);
}

void merge(int x, int y)
{
    int px = find_parent(x);
    int py = find_parent(y);

    if(px == py) return;

    parent[py] = px;
}

void solve()
{
    int idx = 0;
    while(!st.empty())
    {
        int a = st.top().first;
        int b = st.top().second;
        st.pop();

        if(a == 0)
        {
            merge(adj[b], b);
        }
        else
        {
            if(find_parent(a) == find_parent(b))
            {
                ret[idx++] = true;
            }
            else
            {
                ret[idx++] = false;
            }
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> q;

    int a, b, c;
    for(int i=0; i<n-1; i++)
    {
        cin >> a;
        adj[i+2] = a;
    }

    for(int i=0; i<n-1+q; i++)
    {
        cin >> a;
        if(a == 0)
        {
            cin >> b;
            st.push(make_pair(a, b));
        }
        else if(a == 1)
        {
            cin >> b >> c;
            st.push(make_pair(b, c));
        }
    }

    for(int i=1; i<=n; i++)
    {
        parent[i] = i;
    }

    solve();
    for(int i=q-1; i>=0; i--)
    {
        if(ret[i]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}