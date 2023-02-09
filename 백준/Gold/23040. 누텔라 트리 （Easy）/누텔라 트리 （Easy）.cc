#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <queue>

#define MAX_N 100005

typedef long long ll;
using namespace std;

int n;
ll ret;
int parent[MAX_N];
int childs[MAX_N];
bool isRed[MAX_N];
vector<int> adj[MAX_N];
vector<int> black_nodes;

int find(int here)
{
    if(parent[here] == here)
    {
        return here;
    }
    else
    {
        return parent[here] = find(parent[here]);
    }
}

void merge(int x, int y)
{
    int px = find(x);
    int py = find(y);

    if(px == py) return;

    // py의 부모로 px를 설정
    // py의 자식들은 px의 자식들이 됨
    parent[py] = px;
    childs[px] += childs[py];
    childs[py] = 0;
}

void bfs_merge_reds(int start)
{
    queue<int> q;
    q.push(start);

    while(!q.empty())
    {
        int here = q.front();
        q.pop();

        for(int next: adj[here])
        {
            if(isRed[next] && find(here) != find(next))
            {
                merge(here, next);
                q.push(next);
            }
        }
    }
}

void dfs_count_reds(int black)
{
    for(int next: adj[black])
    {
        if(isRed[next])
        {
            ret += static_cast<ll>(childs[find(next)]);
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    //ifstream fin("test.out");

    cin >> n;

    int from, to;
    for(int i=0; i<n-1; i++)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    string temp;
    cin >> temp;
    memset(isRed, 0, sizeof(isRed));

    for(int i=0; i<n; i++)
    {
        if(temp[i] == 'B')
        {
            black_nodes.push_back(i+1);
        }
        else if(temp[i] == 'R')
        {
            isRed[i+1] = true;
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(isRed[i])
        {
            parent[i] = i;
        }
        else
        {
            parent[i] = -1;
        }

        childs[i] = 1;
    }

    for(int i=1; i<=n; i++)
    {
        if(isRed[i] && find(i) == i)
        {
            bfs_merge_reds(i);
        }
    }

    ret = 0;
    for(int black: black_nodes)
    {
        dfs_count_reds(black);
    }
    cout << ret << '\n';

    //fin.close();

    return 0;
}