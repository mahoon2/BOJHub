#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	parent[start] = start;
	
	while(!q.empty())
	{
		int here = q.front();
		q.pop();
		for(int i=0; i<adj[here].size(); i++)
		{
			int there = adj[here][i];
			if(parent[there] == 0)
			{
				parent[there] = here;
				q.push(there);
			}
		}
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n, from, to;
	cin >> n;
	adj = vector<vector<int>>(n+1, vector<int>(0));
	parent = vector<int>(n+1, 0);
	for(int i=0; i<n-1; i++)
	{
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	bfs(1);
	for(int i=2; i<n+1; i++)
		cout << parent[i] << '\n';
	return 0;
}