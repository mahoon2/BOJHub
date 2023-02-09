#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_V 10001
#define swap(x, y); {int temp=y; y=x; x=temp;}

using namespace std;

int v;
vector<pair<int,int>> adj[MAX_V];

class DisjointSet
{
	private:
	vector<int> parent, rank;
	
	public:
	DisjointSet(int n)
	{
		parent = vector<int>(n);
		rank = vector<int>(n, 1);
		for(int i=0; i<n; i++)
			parent[i] = i;
	}
	
	int find(int u)
	{
		if(u == parent[u]) return u;
		else return parent[u] = find(parent[u]);
	}
	
	void merge(int u, int v)
	{
		u = find(u), v = find(v);
		if(u == v) return;
		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(rank[u] == rank[v]) ++rank[v];
	}
};

int kruskal()
{
	int ret = 0;
	vector<pair<int,pair<int,int>>> weighted;
	
	for(int from=1; from<=v; from++)
		for(auto& edge_pair: adj[from])
		{
			int cost = edge_pair.first, to = edge_pair.second;
			weighted.push_back(make_pair(cost, make_pair(from, to)));
		}
	sort(weighted.begin(), weighted.end());
	DisjointSet set(v+1);
	
	for(auto& edge: weighted)
	{
		int cost = edge.first, from = edge.second.first, to = edge.second.second;
		if(set.find(from) == set.find(to)) continue;
		set.merge(from, to);
		ret += cost;
	}
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int e;
	
	cin >> v >> e;
	int from, to, cost;
	while(e--)
	{
		cin >> from >> to >> cost;
		adj[from].push_back(make_pair(cost, to));
	}
	
	cout << kruskal() << '\n';
	return 0;
}