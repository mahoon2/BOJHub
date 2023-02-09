#include <iostream>
#include <vector>
#include <utility>
#define INF 987654321

using namespace std;

int n, m;
int adj[101][101];

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	
	for(int i=0; i<101; i++)
		for(int j=0; j<101; j++)
			if(i==j)
				adj[i][j] = 0;
			else
				adj[i][j] = INF;
	
	int from, to, weight;
	for(int i=0; i<m; i++)
	{
		cin >> from >> to >> weight;
		if(adj[from][to] > weight)
			adj[from][to] = weight;
	}
	
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			if(adj[i][j] >= INF)
				cout << 0 << " ";
			else
				cout << adj[i][j] << " ";
		cout << '\n';
	}
	
	return 0;
}