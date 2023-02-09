#include <iostream>
#include <vector>
#include <queue>

#define MAX_V 100001

using namespace std;

int v;
vector<pair<int,int>> adj[MAX_V];

int prim()
{
	int ret = 0, max_edge = 0;
	vector<bool> added(v+1, false);
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(0, 1));
	
	while(!pq.empty())
	{
		int cost = -pq.top().first, here = pq.top().second;
		pq.pop();
		if(added[here]) continue;
		added[here] = true;
		ret += cost;
		if(max_edge < cost) max_edge = cost;
		
		for(auto& edge_pair: adj[here])
		{
			int next_cost = edge_pair.first, next = edge_pair.second;
			if(!added[next])
				pq.push(make_pair(-next_cost, next));
		}
	}
	
	return ret - max_edge;
}

int main()
{
	int e;
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> v >> e;
	
	int from, to, cost;
	while(e--)
	{
		cin >> from >> to >> cost;
		adj[from].push_back(make_pair(cost, to));
		adj[to].push_back(make_pair(cost, from));
	}
	
	cout << prim() << '\n';
	return 0;
}