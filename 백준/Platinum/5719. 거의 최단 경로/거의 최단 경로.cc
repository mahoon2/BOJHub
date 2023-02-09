#include <iostream>
#include <queue>

#define MAX_V 501
#define INF 987654321

using namespace std;

int n, s, d;
int dist[MAX_V];
int adj[MAX_V][MAX_V];

void dist_reset()
{
	for(int i=0; i<n; i++)
		dist[i] = INF;
}

void dijkstra()
{
	dist[s] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(0, s));

	while(!pq.empty())
	{
		auto here_pair = pq.top();
		pq.pop();
		int cost = -here_pair.first, here = here_pair.second;

		if(cost > dist[here]) continue;
		for(int there=0; there<n; there++)
		{
			if(adj[here][there])
			{
				int next_dist = adj[here][there] + cost;
				if(next_dist < dist[there])
				{
					dist[there] = next_dist;
					pq.push(make_pair(-next_dist, there));
				}
			}
		}
	}
}

void erase_shortest_pairs()
{
	queue<int> q;
	q.push(d);

	vector<bool> visited(n, false);
	while(!q.empty())
	{
		int here = q.front();
//		visited[here] = true;
		q.pop();
		
		for(int there=0; there<n; there++)
		{
			if(adj[there][here] && dist[there] + adj[there][here] == dist[here] && !visited[there])
			{
				adj[there][here] = 0;
				q.push(there);
			}
		}
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	while(true)
	{
		int m;
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		cin >> s >> d;
		
		dist_reset();
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				adj[i][j] = 0;
		
		int from, to, cost;
		while(m--)
		{
			cin >> from >> to >> cost;
			adj[from][to] = cost;
		}

		dijkstra();
		erase_shortest_pairs();

		dist_reset();
		dijkstra();
		if(dist[d] == INF) cout << -1 << '\n';
		else cout << dist[d] << '\n';
	}
	return 0;
}