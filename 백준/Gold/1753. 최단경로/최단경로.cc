#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 3000000

using namespace std;

int v, e;
vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(int start)
{
	vector<int> dist(v+1, INF);
	dist[start] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(0, start));
	
	while(!pq.empty())
	{
		int weight = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if(dist[here] < weight) continue;
		for(int i=0; i<adj[here].size(); i++)
		{
			int next_dist = weight + adj[here][i].first;
			int there = adj[here][i].second;
			if(dist[there] > next_dist)
			{
				dist[there] = next_dist;
				pq.push(make_pair(-next_dist, there));
			}
		}
	}
	
	return dist;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	int start, from, to, weight;
	cin >> v >> e;
	cin >> start;
	
	adj = vector<vector<pair<int,int>>>(v+1);
	for(int i=0; i<e; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back(make_pair(weight, to));
	}
	
	vector<int> dist = dijkstra(start);
	for(int i=1; i<=v; i++)
		if(dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	return 0;
}