#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

#define MAX_N 2*10002

using namespace std;

int n;
vector<int> adj[MAX_N];
stack<int> st;
int visited[MAX_N];
int sccNum[MAX_N];
int node_cnt = 0;
int scc_cnt = 0;

int scc(int here)
{
    int ret = visited[here] = ++node_cnt;
    st.push(here);

    for(int there: adj[here])
    {
        if(visited[there] == -1)
        {
            ret = min(ret, scc(there));
        }
        else if(sccNum[there] == -1)
        {
            ret = min(ret, visited[there]);
        }
    }

    if(ret == visited[here])
    {
        while(true)
        {
            int temp = st.top();
            st.pop();
            sccNum[temp] = scc_cnt;
            if(temp == here) break;
        }
        scc_cnt++;
    }

    return ret;
}

inline int convert(int p)
{
    if(p < 0) return 2*(-p)+1;
    else return 2*p;
}

inline int notX(int p)
{
    return p%2? p-1 : p+1;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m;

    int p, q;
    while(m--)
    {
        // p or q 는 ~p->q, ~q->p 간선으로 취급
        cin >> p >> q;
        p = convert(p); q = convert(q);
        adj[notX(p)].push_back(q);
        adj[notX(q)].push_back(p);
    }

    memset(visited, -1, sizeof(visited));
    memset(sccNum, -1, sizeof(sccNum));
    for(int i=1; i<=n; i++)
    {
        int temp = convert(i);
        int ntemp = notX(temp);
        if(visited[temp] == -1)
        {
            scc(temp);
        }
        if(visited[ntemp] == -1)
        {
            scc(ntemp);
        }
    }

    for(int i=1; i<=n; i++)
    {
        int temp = convert(i);

        /*cout << temp << "(" << sccNum[temp] << "): ";
        for(int there: adj[temp])
        {
            cout << there << " ";
        }
        cout << '\n';
        cout << notX(temp) << "(" << sccNum[notX(temp)] << "): ";
        for(int there: adj[notX(temp)])
        {
            cout << there << " ";
        }
        cout << '\n';*/

        if(sccNum[temp] == sccNum[notX(temp)])
        {
            cout << "0\n";
            return 0;
        }
    }

    cout << "1\n";
    return 0;
}