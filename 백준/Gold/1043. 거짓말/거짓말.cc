#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<bool> knowTruth;
vector<vector<int>> party, adj;

void dfs(int here)
{
	knowTruth[here] = true;
	for(int i=0; i<adj[here].size(); i++)
	{
		int there = adj[here][i];
		if(!knowTruth[there])
			dfs(there);
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	knowTruth = vector<bool> (n+1, false);
	party = vector<vector<int>> (m, vector<int>(0));
	adj = vector<vector<int>> (n+1, vector<int>(0));
	
	int temp, person;
	cin >> temp;
	if(temp == 0) {cout << m << '\n'; return 0;}
	while(temp--)
	{
		cin >> person;
		knowTruth[person] = true;
	}
	
	for(int i=0; i<m; i++)
	{
		int from, to;
		cin >> temp;
		temp--;
		cin >> from;
		party[i].push_back(from);
		
		while(temp--)
		{
			cin >> to;
			party[i].push_back(to);
			adj[from].push_back(to);
			adj[to].push_back(from);
		}
	}
	
	for(int i=1; i<=n; i++)
		if(knowTruth[i])
			dfs(i);
	
	int cnt = 0;
	for(int i=0; i<m; i++)
	{
		int lie = true;
		for(int j=0; j<party[i].size(); j++)
			if(knowTruth[party[i][j]])
			{
				lie = false;
				break;
			}
		if(lie)
			cnt++;
	}
	cout << cnt << '\n';
		
	return 0;
}