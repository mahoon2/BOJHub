#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAX_V 801
#define INF 200000001

using namespace std;

int n;
int dist[3][MAX_V];
vector<pair<int,int>> adj[MAX_V];

void dist_reset()
{
	for(int j=0; j<3; j++)
		for(int i=0; i<=n; i++)
			dist[j][i] = INF;
}

void dijkstra(int start, int index)
{
	dist[index][start] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(0, start));

	while(!pq.empty())
	{
		int cost = -pq.top().first, here = pq.top().second;
		pq.pop();

		if(cost > dist[index][here]) continue;

		for(int i=0; i<adj[here].size(); i++)
		{
			int there = adj[here][i].second, next_dist = adj[here][i].first + cost;
			if(next_dist < dist[index][there])
			{
				dist[index][there] = next_dist;
				pq.push(make_pair(-next_dist, there));
			}
		}
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	int e;
	cin >> n >> e;

	int from, to, cost;
	while(e--)
	{
		cin >> from >> to >> cost;
		adj[from].push_back(make_pair(cost, to));
		adj[to].push_back(make_pair(cost, from));
	}

	int must1, must2, ret1, ret2;
	cin >> must1 >> must2;
	
	dist_reset();
	dijkstra(1, 0);
	dijkstra(must1, 1);
	dijkstra(must2, 2);

	int ret = 987654321;
	if(dist[0][must1] != INF && dist[1][must2] != INF && dist[2][n] != INF)
		ret = min(ret, dist[0][must1] + dist[1][must2] + dist[2][n]);
	if(dist[0][must2] != INF && dist[2][must1] != INF && dist[1][n] != INF)
		ret = min(ret, dist[0][must2] + dist[2][must1] + dist[1][n]);
	if(ret == 987654321) cout << -1 << '\n';
	else cout << ret << '\n';
	
	return 0;
}