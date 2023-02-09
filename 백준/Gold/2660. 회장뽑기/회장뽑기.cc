#include <iostream>
#include <vector>
#include <cstring>
#define INF 987654321;

using namespace std;

int n;
int dist[51][51];

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i==j) continue;
			else dist[i][j] = INF;
	
	int a, b;
	while(true)
	{
		cin >> a >> b;
		if(a == -1 && b == -1) break;
		dist[a][b] = dist[b][a] = 1;
	}
	
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	
	int ret[51], min_friend = INF;
	vector<int> cand;
	memset(ret, 0, sizeof(ret));
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			ret[i] = max(ret[i], dist[i][j]);
		if(min_friend > ret[i])
		{
			min_friend = ret[i];
			cand.clear();
			cand.push_back(i);
		}
		else if(min_friend == ret[i])
			cand.push_back(i);
	}
	
	cout << min_friend << " " << cand.size() << '\n';
	for(int i: cand)
		cout << i << " ";
	cout << '\n';
	return 0;
}