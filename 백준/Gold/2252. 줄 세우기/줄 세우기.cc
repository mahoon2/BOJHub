#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;
stack<int> ret;

void dfs(int here)
{
	visited[here] = true;
	for(int i=0; i<adj[here].size(); i++)
	{
		int there = adj[here][i];
		if(!visited[there])
			dfs(there);
	}
	ret.push(here);
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int m, smaller, taller;
	cin >> n >> m;
	
	adj = vector<vector<int>> (n+1, vector<int>(0));
	visited = vector<bool> (n+1, false);
	while(m--)
	{
		cin >> smaller >> taller;
		adj[smaller].push_back(taller);
	}
	
	for(int i=1; i<=n; i++)
		if(!visited[i])
			dfs(i);
	
	while(!ret.empty())
	{
		cout << ret.top() << " ";
		ret.pop();
	}
	cout << '\n';
	return 0;
}