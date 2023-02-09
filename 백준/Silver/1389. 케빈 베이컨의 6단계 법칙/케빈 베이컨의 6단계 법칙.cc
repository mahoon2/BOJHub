#include <iostream>
#include <cstring>
#define MAX 987654321

using namespace std;
int n;
bool visited[101] = {false};
int bacon[101][101];

int sol(int x, int y)
{
	int& ret = bacon[x][y];
	if(ret) return ret;
	
	for(int i=1; i<=n; i++)
	{
		if(i==x || i==y)
			continue;
		if(bacon[x][i] && !visited[i])
		{
			if(ret == 0)
			{
				visited[i] = true;
				int temp = sol(i, y);
				if(temp==MAX) continue;
				ret = bacon[x][i] + temp;
				visited[i] = false;
			}
			else
			{
				visited[i] = true;
				ret = min(ret, bacon[x][i] + sol(i, y));
				visited[i] = false;
			}
		}
	}
	
	if(ret)
	{
		bacon[y][x] = ret;
		return ret;
	}
	else
		return MAX;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int m, bacon_sum[101];
	memset(bacon, 0, sizeof(bacon));
	memset(bacon_sum, 0, sizeof(bacon_sum));
	
	cin >> n >> m;
	int temp1, temp2;
	for(int i=0; i<m; ++i)
	{
		cin >> temp1 >> temp2;
		bacon[temp1][temp2] = 1;
		bacon[temp2][temp1] = 1;
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
		{
			visited[i] = visited[j] = true;
			sol(i, j);
			visited[i] = visited[j] = false;
		}
	
	int index, min=MAX;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if(i==j) continue;
			bacon_sum[i] += bacon[i][j];
		}
	
	for(int i=1; i<=n; i++)
		if(min > bacon_sum[i])
		{
			index = i;
			min = bacon_sum[i];
		}
	cout << index << endl;
	return 0;
}