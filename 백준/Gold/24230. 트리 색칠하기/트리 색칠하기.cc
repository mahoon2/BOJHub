#include <iostream>
#include <vector>
#include <cstring>
#define MAX_V 200002

using namespace std;

int n, cnt = 0;
vector<int> adj[MAX_V];
int node_color[MAX_V];
bool visited[MAX_V];

void dfs(int here, int& here_color)
{
	visited[here] = true;
	
	if(node_color[here] == here_color)
	{
		for(int next: adj[here])
			if(!visited[next])
				dfs(next, here_color);
	}
	else
	{
		cnt++;
		int next_color = node_color[here];
		for(int next: adj[here])
			if(!visited[next])
				dfs(next, next_color);
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> node_color[i];
	
	int a, b;
	for(int i=0; i<n-1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int start_color = 0;
	memset(visited, false, sizeof(visited));
	dfs(1, start_color);
	cout << cnt << '\n';
	return 0;
}