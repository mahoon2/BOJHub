#include <iostream>
#include <cstring>

using namespace std;

int n;
int w;
pair<int,int> pos[1003];
pair<int,int> rem[1003][1003];
int dp[1003][1003];

int dist(int idx1, int idx2)
{
	int y = pos[idx1].first - pos[idx2].first;
	int x = pos[idx1].second - pos[idx2].second;
	if(y < 0) y = -y;
	if(x < 0) x = -x;
	return y+x;
}

int solve(int p1, int p2)
{
	int idx = max(p1, p2) + 1;
	int& ret = dp[p1][p2];
	if(idx == w+2) return ret = 0;
	if(ret != -1) return ret;
	
	int p1_ret = solve(idx, p2) + dist(p1, idx);
	int p2_ret = solve(p1, idx) + dist(p2, idx);
	if(p1_ret < p2_ret)
	{
		ret = p1_ret;
		rem[p1][p2] = make_pair(idx, p2);
	}
	else{
		ret = p2_ret;
		rem[p1][p2] = make_pair(p1, idx);
	}
	
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	cin >> n;
	cin >> w;
	int y, x;
	pos[0] = make_pair(0, 0);
	pos[1] = make_pair(n-1, n-1);
	for(int i=2; i<w+2; i++)
	{
		cin >> y >> x;
		y--; x--;
		pos[i] = make_pair(y, x);
	}
	
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 1) << '\n';
	
	/*cout << '\n';
	for(int i=0; i<w+2; i++)
	{
		for(int j=0; j<w+2; j++)
			cout << dp[i][j] << " ";
		cout << '\n';
	}
	
	cout << '\n';
	for(int i=0; i<w+2; i++)
	{
		for(int j=0; j<w+2; j++)
			cout << rem[i][j].first << "," << rem[i][j].second << " ";
		cout << '\n';
	}*/
	
	pair<int,int> here = make_pair(0, 1);
	pair<int,int> next;
	while(here.first != w+1 && here.second != w+1)
	{
		next = rem[here.first][here.second];
		if(here.first != next.first) cout << 1 << '\n';
		else cout << 2 << '\n';
		here = next;
	}
	
	return 0;
}