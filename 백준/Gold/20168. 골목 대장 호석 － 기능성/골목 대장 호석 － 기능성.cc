#include <iostream>
#include <cstring>

#define INF 987654321

using namespace std;

int ret = INF;
int n, start, dest, money;
int adj[11][11];
bool visited[11];

void solve(int here, int here_dist, int here_cost)
{
	if(here_dist > money) return;
	if(here == dest) { ret = min(ret, here_cost); return; }
	
	for(int i=1; i<=n; i++)
	{
    	if(!adj[here][i] || visited[i]) continue;
        visited[i] = true;
        solve(i, here_dist + adj[here][i], max(here_cost, adj[here][i]));
        visited[i] = false;
    }
}

int main()
{
	//cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m >> start >> dest >> money;
	
	memset(adj, 0, sizeof(adj));
	int from, to, cost;
	while(m--)
	{
		cin >> from >> to >> cost;
		adj[from][to] = cost;
		adj[to][from] = cost;
	}
	
	solve(start, 0, 0);
	
	if(ret == INF) cout << "-1\n";
	else cout << ret << '\n';
	return 0;
}