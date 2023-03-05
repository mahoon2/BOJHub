#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_N 328001

using namespace std;

int n;
int s; // 1~S번까지는 지지대
int p;
vector<int> adj[MAX_N];
int dist[MAX_N];

int bfs(int start)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty())
    {
        int here = q.front();
        q.pop();

        for(int& there: adj[here])
        {
            if(dist[there] == -1)
            {
                dist[there] = dist[here]+1;
                q.push(there);
            }
        }
    }

    int first_min_idx = 1;
    for(int i=2; i<=s; i++)
    {
        if(dist[i] < dist[first_min_idx])
        {
            first_min_idx = i;
        }
    }

    int second_min_idx = -1;
    for(int i=1; i<=s; i++)
    {
        if(i != first_min_idx && (second_min_idx == -1 || dist[i] < dist[second_min_idx]))
        {
            second_min_idx = i;
        }
    }

//    cout << first_min_idx << " " << second_min_idx << '\n';
    return n-dist[first_min_idx]-dist[second_min_idx]-1;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> s >> p;
    int from, to;
    for(int i=0; i<n-1; i++)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    memset(dist, -1, sizeof(dist));
    cout << bfs(p) << '\n';

    return 0;
}