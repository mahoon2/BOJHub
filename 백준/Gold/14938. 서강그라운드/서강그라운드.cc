#include <iostream>
#include <queue>
#include <utility>

#define INF 987654321
#define MAX_V 101

using namespace std;

int n, m, ret = 0;
int item[MAX_V], dist[MAX_V];
vector<pair<int,int>> adj[MAX_V];

void dist_reset()
{
	for(int i=0; i<=n; i++)
		dist[i] = INF;
}

void dijkstra(int start)
{
	dist[start] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(0, start));

	int item_sum = 0;
	while(!pq.empty())
	{
		int cost = -pq.top().first, here = pq.top().second;
		pq.pop();
		
		if(cost > dist[here]) continue;
		item_sum += item[here];
		for(auto next: adj[here])
		{
			int next_dist = next.first + cost, there = next.second;
			if(next_dist < dist[there] && next_dist <= m)
			{
				dist[there] = next_dist;
				pq.push(make_pair(-next_dist, there));
			}
		}
	}

	ret = max(ret, item_sum);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int r;
	cin >> n >> m >> r;
	for(int i=1; i<=n; i++)
		cin >> item[i];

	int from, to, cost;
	while(r--)
	{
		cin >> from >> to >> cost;
		adj[from].push_back(make_pair(cost, to));
		adj[to].push_back(make_pair(cost, from));
	}

	for(int i=1; i<=n; i++)
	{
		dist_reset();
		dijkstra(i);
	}
	cout << ret << '\n';
	return 0;
}