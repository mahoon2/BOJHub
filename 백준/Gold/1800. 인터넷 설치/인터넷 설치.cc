#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define MAX_N 1002
#define INF 987654321

using namespace std;

int n, k;
vector<pair<int,int>> adj[MAX_N];
bool visited[MAX_N];
int dist[MAX_N];
int ret;

void check_for_free(int start)
{
    queue<pair<int, int>> q;
    q.push(make_pair(0, start));

    while(!q.empty())
    {
        auto p = q.front();
        q.pop();

        int dist = p.first;
        int here = p.second;
        visited[here] = true;

        if(here == n)
        {
            ret = dist;
            return;
        }

        for(auto& p: adj[here])
        {
            int next = p.second;
            if(!visited[next])
            {
                q.push(make_pair(dist+1, next));
            }
        }
    }
}

bool check(int thresold)
{
    // thresold를 초과하는 값이 K개가 넘지 않도록
    // 1~N 까지의 경로를 구성할 수 있는가?

    for(int i=0; i<=n; i++)
    {
        dist[i] = INF;
    }
    memset(visited, 0, sizeof(visited));

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0, 1));
    dist[0] = 0;

    while(!pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        int cost = -p.first;
        int here = p.second;
        visited[here] = true;
        
        if(here == n)
        {
            if(dist[n] <= k) return true;
            else return false;
        }

        if(cost > dist[here]) continue;

        for(auto& next_p: adj[here])
        {
            int next = next_p.second;
            int next_cost = cost;
            if(next_p.first > thresold) next_cost += 1;

            if(next_cost < dist[next] && !visited[next])
            {
                dist[next] = next_cost;
                pq.push(make_pair(-next_cost, next));
            }
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int p;
    cin >> n >> p >> k;

    int from, to, cost;
    for(int i=0; i<p; i++)
    {
        cin >> from >> to >> cost;
        adj[from].push_back(make_pair(cost, to));
        adj[to].push_back(make_pair(cost, from));
    }

    ret = -1;
    memset(visited, 0, sizeof(visited));
    check_for_free(1);

    if(ret == -1)
    {
        cout << -1 << '\n';
    }
    else if(ret <= k)
    {
        cout << 0 << '\n';
    }
    else
    {
        int lo = 0; // false
        int hi = 1000000; // true

        while(hi - lo != 1)
        {
            int mid = (lo + hi) / 2;
            if(check(mid))
                hi = mid;
            else
                lo = mid;
        }

        cout << hi << '\n';
    }

    return 0;
}