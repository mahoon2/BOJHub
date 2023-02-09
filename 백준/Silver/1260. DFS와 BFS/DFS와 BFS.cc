#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int discovered[1001];
int adj[1001][1001];
int n;

void dfs(int here)
{
	cout << here << ' ';
	discovered[here] = 1;
	
	for(int i=1; i<=n; i++)
		if(adj[here][i] && !discovered[i])
			dfs(i);
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	discovered[start] = 1;
	
	while(!q.empty())
	{
		int here = q.front();
		q.pop();
		cout << here << ' ';
		
		for(int i=1; i<=n; i++)
			if(adj[here][i] && !discovered[i])
			{
				q.push(i);
				discovered[i] = 1;
			}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	memset(discovered, 0, sizeof(discovered));
	memset(adj, 0, sizeof(adj));
	
	int m, start;
	cin >> n >> m >> start;
	
	int from, to;
	for(int i=0; i<m; i++)
	{
		cin >> from >> to;
		adj[from][to] += 1;
		adj[to][from] += 1;
	}
	
	dfs(start);
	cout << '\n';
	memset(discovered, 0, sizeof(discovered));
	bfs(start);
	cout << '\n';
	return 0;
}