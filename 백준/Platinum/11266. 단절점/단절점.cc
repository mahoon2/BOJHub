#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_V 10001

using namespace std;

int v, cnt = 1;
vector<int> visited;
vector<bool> is_ap(MAX_V, false);
vector<int> adj[MAX_V];

int dfs(int prev, int here, bool isroot)
{
	visited[here] = cnt++;
	int ret = visited[here];
	int childcnt = 0;
	
	for(int there: adj[here])
	{
		if(there == prev) continue;
		if(visited[there] == -1)
		{
			childcnt++;
			int subtree = dfs(here, there, false);
			if(!isroot && subtree >= visited[here])
				is_ap[here] = true;
			ret = min(ret, subtree);
		}
		else if(visited[there])
		{
			ret = min(ret, visited[there]);
		}
	}
	
	if(isroot && childcnt >= 2)
		is_ap[here] = true;
	
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int e;
	cin >> v >> e;
	
	int from, to;
	while(e--)
	{
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	
	visited = vector<int> (v+1, -1);
	for(int i=1; i<=v; i++)
		if(visited[i] == -1)
			dfs(0, i, true);
	
	int ret = 0;
	for(int i=1; i<=v; i++)
		if(is_ap[i]) ret++;
	
	cout << ret << '\n';
	for(int i=1; i<=v; i++)
		if(is_ap[i])
			cout << i << " ";
	cout << '\n';
	
	return 0;
}