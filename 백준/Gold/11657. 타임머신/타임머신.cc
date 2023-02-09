#include <iostream>
#include <vector>
#define MAX_V 501
#define INF 922337203685477580
#define N_INF -922337203685477580
typedef long long ll;

using namespace std;

int n;
vector<pair<int,int>> adj[MAX_V];
vector<ll> dist;

vector<ll> bellman_ford(int start)
{
	dist[start] = 0;
	
	bool updated;
	for(int iter=0; iter<n; iter++)
	{
		updated = false;
		for(int here=1; here<=n; here++)
		{
			if(dist[here] == N_INF) continue;
			for(int i=0; i<adj[here].size(); i++)
			{
				ll cost = adj[here][i].first;
				int	there = adj[here][i].second;
				if(dist[there] > dist[here] + cost)
				{
					dist[there] = dist[here] + cost;
					updated = true;
				}
			}
		}
		
		if(!updated) break;
	}
	
	if(updated) dist.clear();
	return dist;
}

void dfs(int here, vector<bool>& visited)
{
	visited[here] = true;
	for(int i=0; i<adj[here].size(); i++)
	{
		int there = adj[here][i].second;
		if(!visited[there]) dfs(there, visited);
	}
}

int main()
{
	int m;
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	
	int from, to, cost;
	while(m--)
	{
		cin >> from >> to >> cost;
		adj[from].push_back(make_pair(cost, to));
	}
	
	dist = vector<ll>(n+1, INF);
	vector<bool>visited(n+1, false);
	
	dfs(1, visited);
	for(int i=1; i<=n; i++)
		if(!visited[i])
			dist[i] = N_INF;
	bellman_ford(1);
	
	if(dist.size() == 0) cout << "-1\n";
	else
	{
		ll m = 500*10000 + 1;
		for(int here=2; here<=n; here++)
            if(dist[here] != N_INF)
			    cout << dist[here] << '\n';
            else
                cout << "-1\n";
	}
	
	return 0;
}