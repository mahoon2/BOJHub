#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[20002];

int bfs(int start, int n)
{
    queue<pair<int,int>> q;
    vector<bool> visited (n+1, false);
    q.push(make_pair(0, start));
    visited[start] = true;
    
    int maxDist = -1;
    int ret = 0;
    
    while(!q.empty())
    {
        auto [dist, here] = q.front();
        q.pop();
        
        if(maxDist == dist) ret++;
        else if(maxDist < dist)
        {
            maxDist = dist;
            ret = 1;
        }
        
        for(auto next: adj[here])
        {
            if(!visited[next])
            {
                q.push(make_pair(dist+1, next));
                visited[next] = true;
            }
        }
    }
    
    return ret;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(auto& i: edge)
    {
        int a = i[0]; int b = i[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    return answer = bfs(1, n);
}