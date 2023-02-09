#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<int> adj[10001];
int cost[10001], dist[10001], indegree[10001];
bool visited[10001];

int n;

int solve()
{
	int ret = 0;
	priority_queue<pair<int,int>> pq;
	
	for(int i=1; i<=n; i++)
		if(indegree[i] == 0)
		{
			dist[i] = cost[i];
			pq.push(make_pair(dist[i], i));
		}
	
	while(!pq.empty())
	{
		int here_dist = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		
		visited[here] = true;
		ret = max(ret, dist[here]);
		
		for(int there: adj[here])
		{
			indegree[there]--;
			dist[there] = max(dist[there], dist[here]+cost[there]);
			if(!visited[there] && indegree[there] == 0)
				pq.push(make_pair(dist[there], there));
		}
	}
	
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	
	int m, temp;
	for(int i=1; i<=n; i++)
	{
		cin >> cost[i] >> m;
		indegree[i] = m;
		while(m--)
		{
			cin >> temp;
			adj[temp].push_back(i);
		}
	}
	
	memset(visited, false, sizeof(visited));
	memset(dist, -1, sizeof(dist));
	cout << solve() << '\n';
	return 0;
}