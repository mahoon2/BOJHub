#include <iostream>
#include <vector>
#include <utility>
#define INF 987654321

using namespace std;

int n;
vector<vector<pair<int,int>>> adj;

bool bellman_ford()
{
	vector<int> upper(n+1, INF);
	upper[1] = 1;
	bool updated;
	
	for(int iter=1; iter<n+1; iter++)
	{
		updated = false;
		for(int here=1; here<n+1; here++)
			for(int i=0; i<adj[here].size(); i++)
			{
				int weight = adj[here][i].first;
				int there = adj[here][i].second;
				if(upper[there] > upper[here] + weight)
				{
					upper[there] = upper[here] + weight;
					updated = true;
				}
			}
		
		if(!updated) break;
	}
	return updated;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	int tc, m, w;
	cin >> tc;
	while(tc--)
	{
		cin >> n >> m >> w;
		adj = vector<vector<pair<int,int>>>(n+1, vector<pair<int,int>>(0));
		int s, e, t;
		
		for(int i=0; i<m; i++)
		{
			cin >> s >> e >> t;
			adj[s].push_back(make_pair(t, e));
			adj[e].push_back(make_pair(t, s));
		}
		for(int i=0; i<w; i++)
		{
			cin >> s >> e >> t;
			adj[s].push_back(make_pair(-t, e));
		}
		if(bellman_ford()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}