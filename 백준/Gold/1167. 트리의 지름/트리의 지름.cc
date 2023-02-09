#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<bool> visited;

int v, start, far, far_node;

void dfs(int here, int cost)
{
	visited[here] = true;
	if(far < cost) {far = cost; far_node=here;}
	
	for(int i=0; i<adj[here].size(); i++)
	{
		const auto& there = adj[here][i];
		if(!visited[there.second])
			dfs(there.second, cost + there.first);
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> v;
	adj = vector<vector<pair<int,int>>> (v+1, vector<pair<int,int>>(0));
	
	int parent, child, cost;
	for(int i=1; i<v+1; i++)
	{
		cin >> parent;
		while(true)
		{
			cin >> child;
			if(child == -1)
				break;
			cin >> cost;
			adj[parent].push_back(make_pair(cost, child));
			adj[child].push_back(make_pair(cost, parent));
		}
	}
	
	far = 0;
	visited = vector<bool> (v+1, false);
	start = 1;
	dfs(1, 0);
	
	far = 0;
	visited = vector<bool> (v+1, false);
	start = far_node;
	dfs(far_node, 0);
	
	cout << far << '\n';
	
	return 0;
}