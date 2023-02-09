#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 987654321

using namespace std;

int n;
vector<vector<pair<int,int>>> adj;

int dijkstra(int from, int to)
{
	vector<int> dist(n+1, INF);
	dist[from] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(0, from));
	
	while(!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		
		if(dist[here] < cost) continue;
		for(int i=0; i<adj[here].size(); i++)
		{
			int there = adj[here][i].second;
			int nextDist = adj[here][i].first + cost;
			if(dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
		
	return dist[to];
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	int m, from, to, cost;
	cin >> n >> m;
	adj = vector<vector<pair<int,int>>> (n+1, vector<pair<int,int>>(0));
	for(int i=0; i<m; i++)
	{
		cin >> from >> to >> cost;
		adj[from].push_back(make_pair(cost, to));
	}
	cin >> from >> to;
	
	cout << dijkstra(from, to) << '\n';
	return 0;
}