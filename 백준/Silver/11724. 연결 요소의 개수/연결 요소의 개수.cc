#include <iostream>
#include <vector>

using namespace std;

int n, cnt = 0, visited[1001] = {0};
vector<vector<int>> adj;

void dfs(int here)
{
	visited[here] = 1;
	for(int i=0; i<adj[here].size(); i++)
	{
		int there = adj[here][i];
		if(!visited[there]) dfs(there);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int m, from, to;
	cin >> n >> m;
	
	adj = vector<vector<int>>(n+1);
	for(int i=0; i<m; i++)
	{
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	
	for(int i=1; i<=n; i++)
		if(!visited[i])
		{
			cnt++;
			dfs(i);
		}
	
	cout << cnt << '\n';
	return 0;
}