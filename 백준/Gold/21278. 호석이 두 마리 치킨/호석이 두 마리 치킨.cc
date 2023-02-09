#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX_V 101
#define INF 987654321

using namespace std;

int n;
int dist[MAX_V][MAX_V];
vector<pair<int,pair<int,int>>> ret;

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int m, from, to;
	cin >> n >> m;
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i==j) dist[i][j] = 0;
			else dist[i][j] = INF;
	
	while(m--)
	{
		cin >> from >> to;
		dist[from][to] = dist[to][from] = 1;
	}
	
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
		{
			if(dist[i][k] == INF) continue;
			for(int j=1; j<=n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
		{
			int sum = 0;
			for(int k=1; k<=n; k++)
				sum += min(dist[i][k], dist[j][k]);
			sum *= 2;
			ret.push_back(make_pair(sum, make_pair(i, j)));
		}
	
	sort(ret.begin(), ret.end());
	cout << ret[0].second.first << " " << ret[0].second.second << " " << ret[0].first << '\n';
}