#include <iostream>
#include <cstring>

using namespace std;

int n;
int adj[16][16];
int dp[16][1<<16];

int tsp(int here, int visited)
{
	int &ret = dp[here][visited];
	if(visited == (1<<n)-1)
		return ret = (adj[here][0]? adj[here][0] : 16000001);
	if(ret != -1) return ret;
	
	ret = 16000001;
	for(int i=0; i<n; i++)
		if(adj[here][i] && !(visited & (1<<i)))
			ret = min(ret, adj[here][i] + tsp(i, visited | (1<<i)));
	
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> adj[i][j];
	
	memset(dp, -1, sizeof(dp));
	cout << tsp(0, 1) << '\n';
	return 0;
}