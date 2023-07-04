#include <iostream>
#include <stack>
#include <array>
#include <set>
#define MAX_N 100002

using namespace std;

int n, q;
int inp_parent[MAX_N], parent[MAX_N];
set<int> colors[MAX_N];

int find_parent(int here)
{
    if(parent[here] == here) return here;
    else return parent[here] = find_parent(parent[here]);
}

void merge(int x, int y)
{
    int px = find_parent(x);
    int py = find_parent(y);

    if(px == py) return;

    if(colors[px].size() > colors[py].size())
    {
        swap(px, py);
    }

    parent[px] = py;
    for(int i: colors[px])
    {
        colors[py].insert(i);
    }
    colors[px].clear();
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> q;
    q += n-1;

    // 루트는 1번
    inp_parent[1] = 1;
    for(int i=0; i<n-1; i++)
    {
        cin >> inp_parent[i+2];
    }

    int temp;
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        colors[i+1].insert(temp);
        parent[i+1] = i+1;
    }

    stack<array<int, 2>> st;
    int q1, q2;
    while(q--)
    {
        cin >> q1 >> q2;
        st.push({q1, q2});
    }

    array<int,2> t;
    stack<int> ret;
    while(!st.empty())
    {
        t = st.top();
        st.pop();

        if(t[0] == 1)
        {
            merge(t[1], inp_parent[t[1]]);
        }
        else
        {
            ret.push(colors[find_parent(t[1])].size());
        }
    }

    while(!ret.empty())
    {
        cout << ret.top() << '\n';
        ret.pop();
    }

    return 0;
}