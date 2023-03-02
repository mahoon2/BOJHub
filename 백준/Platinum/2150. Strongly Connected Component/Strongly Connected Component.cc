#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

#define MAX_V 10001

using namespace std;

int v;
vector<int> adj[MAX_V];
int vCount = 0;
int sccCount = 0;

int visited[MAX_V];
int sccNum[MAX_V];
stack<int> st;

bool comp(vector<int>& a, vector<int>& b)
{
    if(a[0] < b[0]) return true;
    else return false;
}

int scc(int here)
{
    // 방문한 순서대로 번호를 매긴 후
    // 내가 갈 수 있는 가장 얕은 번호를 반환한다.

    int ret = visited[here] = ++vCount;
    st.push(here);

    for(int there: adj[here])
    {
        // 아직 방문되지 않음 -> 이 간선은 트리 간선(부모->자식 관계)
        if(visited[there] == -1)
        {
            ret = min(ret, scc(there));
        }
        // 이 정점은 방문되었으나 scc로 묶이지 않음 -> 이 간선은 교차 간선 or 역방향 간선
        // 하지만 아직 scc로 묶이지 않았으므로 무시할 수 없는 교차 간선임
        // (조상으로 올라갈 수 있을수도 있음)
        else if(sccNum[there] == -1)
        {
            ret = min(ret, visited[there]);
        }
        // 이미 묶인 교차간선은 무시한다.
    }

    if(ret == visited[here])
    {
        while(true)
        {
            int t = st.top();
            st.pop();
            sccNum[t] = sccCount;
            if(t == here) break;
        }
        ++sccCount;
    }
    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int e;
    cin >> v >> e;

    int from, to;
    while(e--)
    {
        cin >> from >> to;
        adj[from].push_back(to);
    }

    memset(visited, -1, sizeof(visited));
    memset(sccNum, -1, sizeof(sccNum));
    for(int i=1; i<=v; i++)
    {
        if(visited[i] == -1)
        {
            scc(i);
        }
    }

    vector<vector<int>> sccRet(sccCount);
    for(int i=1; i<=v; i++)
    {
        sccRet[sccNum[i]].push_back(i);
    }
    sort(sccRet.begin(), sccRet.end(), comp);

    cout << sccCount << '\n';
    for(auto& vec: sccRet)
    {
        for(int i: vec)
        {
            cout << i << " ";
        }
        cout << "-1\n";
    }
    
    return 0;
}