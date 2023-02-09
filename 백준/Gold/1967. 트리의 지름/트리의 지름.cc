#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, max_dist, far_node;
vector<vector<pair<int,int>>> adj;
vector<bool> visited;

void dfs(int here, int cost)
{
	visited[here] = true;
	if(cost > max_dist)
	{
		max_dist = cost;
		far_node = here;
	}
	
	for(int i=0; i<adj[here].size(); i++)
	{
		int there = adj[here][i].second;
		int next_dist = adj[here][i].first + cost;
		if(!visited[there])
			dfs(there, next_dist);
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	
	adj = vector<vector<pair<int,int>>> (n+1, vector<pair<int,int>>(0));
	int parent, child, cost;
	for(int i=0; i<n-1; i++)
	{
		cin >> parent >> child >> cost;
		adj[parent].push_back(make_pair(cost, child));
		adj[child].push_back(make_pair(cost, parent));
	}
	
	visited = vector<bool> (n+1, false);
	max_dist = 0;
	dfs(1, 0);
	visited = vector<bool> (n+1, false);
	max_dist = 0;
	dfs(far_node, 0);
	cout << max_dist << '\n';

	return 0;
}