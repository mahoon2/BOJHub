#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX_V 1001

using namespace std;

int n, x;
vector<pair<int,int>> adj[MAX_V];
vector<int> dist;

int dijkstra(int start)
{
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(0, start));
	dist = vector<int> (n+1, INF);
	dist[start] = 0;
	
	while(!pq.empty())
	{
		pair<int,int> here_pair = pq.top();
		pq.pop();
		int here_dist = -here_pair.first, here = here_pair.second;
		
		if(here_dist > dist[here]) continue;
		if(start != x && here == x) return dist[x];
		for(pair<int,int> next_pair: adj[here])
		{
			int next_dist = next_pair.first + here_dist, next = next_pair.second;
			if(dist[next] > next_dist)
			{
				dist[next] = next_dist;
				pq.push(make_pair(-next_dist, next));
			}
		}
	}
	
	return INF;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m >> x;
	int from, to, cost;
	while(m--)
	{
		cin >> from >> to >> cost;
		adj[from].push_back(make_pair(cost, to));
	}
	
	int ret[MAX_V], ret_max = 0;
	for(int i=1; i<=n; i++)
	{
		if(i == x) ret[i] = 0;
		else ret[i] = dijkstra(i);
	}
	dijkstra(x);
	for(int i=1; i<=n; i++)
	{
		if(i == x) continue;
		ret[i] += dist[i];
		if(ret_max < ret[i]) ret_max = ret[i];
	}
	cout << ret_max << '\n';
	return 0;
}