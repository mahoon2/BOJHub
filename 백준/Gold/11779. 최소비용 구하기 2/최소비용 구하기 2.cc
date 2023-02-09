#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#define MAX_V 1001
#define INF 987654321

using namespace std;

int n;
vector<pair<int,int>> adj[MAX_V];

void dijkstra(int start, int end)
{
	vector<int> dist(n+1, INF), prev(n+1);
	dist[start] = 0, prev[start] = start;
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(0, start));
	
	while(!pq.empty())
	{
		auto here_pair = pq.top();
		pq.pop();
		int here_dist = -here_pair.first, here = here_pair.second;
		
		if(here_dist > dist[here]) continue;
		if(here == end) break;
		
		for(auto next_pair: adj[here])
		{
			int next_dist = next_pair.first + here_dist, next = next_pair.second;
			if(dist[next] > next_dist)
			{
				dist[next] = next_dist;
				prev[next] = here;
				pq.push(make_pair(-next_dist, next));
			}
		}
	}
	
	int here = end, cnt = 1;
	stack<int> route;
	route.push(here);
	while(prev[here] != here)
	{
		here = prev[here];
		route.push(here);
		cnt++;
	}
	
	cout << dist[end] << '\n';
	cout << cnt << '\n';
	while(!route.empty())
	{
		cout << route.top() << " ";
		route.pop();
	}
	cout << '\n';
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	
	int from, to, cost;
	while(m--)
	{
		cin >> from >> to >> cost;
		adj[from].push_back(make_pair(cost, to));
	}
	
	int start, end;
	cin >> start >> end;
	dijkstra(start, end);
	
	return 0;
}