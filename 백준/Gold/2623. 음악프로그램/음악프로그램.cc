#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> ret;
int n;
bool solve_possible = true;

void dfs(int here)
{
	visited[here] = true;
	for(int there: adj[here])
	{
		if(!visited[there])
			dfs(there);
		else
		{
			bool isDfsOver = false;
			for(int i=0; i<ret.size(); i++)
				if(there == ret[i])
				{
					isDfsOver = true;
					break;
				}
			if(!isDfsOver)
			{
				solve_possible = false;
				return;
			}
		}
	}
	ret.push_back(here);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	adj = vector<vector<int>> (n+1, vector<int>(0));
	visited = vector<bool> (n+1, false);

	int m, rep, from, to;
	cin >> m;
	while(m--)
	{
		cin >> rep;
		rep--;
		cin >> from;
		while(rep--)
		{
			cin >> to;
			adj[from].push_back(to);
			from = to;
		}
	}
	
	for(int i=1; i<=n; i++)
		if(!visited[i] & solve_possible)
			dfs(i);
	
	if(!solve_possible)
		cout << "0\n";
	else
	{
		for(int i=ret.size()-1; i>=0; i--)
			cout << ret[i] << '\n';
	}
	
	return 0;
}