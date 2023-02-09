#include <iostream>
#include <vector>
#include <cstring>
#define MAX_V 1001
#define INF 987654321

using namespace std;

vector<pair<int,int>> adj[MAX_V];
int dist[MAX_V][MAX_V];
int dest;
bool visited[MAX_V];

int dfs(int here)
{
	visited[here] = true;
	for(auto& there_pair: adj[here])
	{
		if(!visited[there_pair.second])
			dist[here][dest] = min(dist[here][dest], there_pair.first + dfs(there_pair.second));
	}
	
	dist[dest][here] = dist[here][dest];
	return dist[here][dest];
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i==j) dist[i][j] = 0;
			else dist[i][j] = INF;
	
	int from, to, c;
	for(int i=0; i<n-1; i++)
	{
		cin >> from >> to >> c;
		adj[from].push_back(make_pair(c, to));
		adj[to].push_back(make_pair(c, from));
		dist[from][to] = dist[to][from] = c;
	}
	
	while(m--)
	{
		cin >> from >> to;
		dest = to;
		memset(visited, false, sizeof(visited));
		cout << dfs(from) << '\n';
	}
	return 0;
}