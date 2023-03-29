#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 1002

using namespace std;

int n;
vector<pair<int,int>> adj[MAX_N];

int find_maximum(int start)
{
    priority_queue<pair<int,int>> pq;
    vector<bool> added(n+1, false);
    int ret = 0;

    pq.push(make_pair(0, 0));
    while(!pq.empty())
    {
        auto here = pq.top();
        pq.pop();

        int dist = here.first; int next = here.second;
        if(added[next]) continue;
        added[next] = true;
        ret += dist;

        for(auto& there: adj[next])
        {
            if(!added[there.second])
            {
                pq.push(make_pair(there.first, there.second));
            }
        }
    }

    return ret;
}

int find_minimum(int start)
{
    priority_queue<pair<int,int>> pq;
    vector<bool> added(n+1, false);
    int ret = 0;

    pq.push(make_pair(0, 0));
    while(!pq.empty())
    {
        auto here = pq.top();
        pq.pop();

        int dist = -here.first; int next = here.second;
        if(added[next]) continue;
        added[next] = true;
        ret += dist;

        for(auto& there: adj[next])
        {
            if(!added[there.second])
            {
                pq.push(make_pair(-there.first, there.second));
            }
        }
    }

    return ret;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m;

    int from, to, dist;
    m++;
    while(m--)
    {
        cin >> from >> to >> dist;
        dist ^= 1;
        adj[from].push_back(make_pair(dist, to));
        adj[to].push_back(make_pair(dist, from));
    }

    int ret1 = find_maximum(0);
    int ret2 = find_minimum(0);

//    cout << ret1 << " " << ret2 << '\n';
    cout << ret1*ret1 - ret2*ret2 << '\n';

    return 0;
}