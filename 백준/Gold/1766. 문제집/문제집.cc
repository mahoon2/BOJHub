#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[32001];
int n, indegree[32001] = {0};

int main()
{
	int m, from, to;
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		cin >> from >> to;
		adj[from].push_back(to);
		++indegree[to];
	}
	
	priority_queue<int> pq;
	for(int i=1; i<=n; i++)
		if(indegree[i] == 0)
			pq.push(-i);
	
	while(!pq.empty())
	{
		int here = -pq.top();
		pq.pop();
		
		cout << here << " ";
		for(int i=0; i<adj[here].size(); i++)
		{
			int next = adj[here][i];
			if(--indegree[next] == 0)
				pq.push(-next);
		}
	}
	cout << '\n';
	return 0;
}