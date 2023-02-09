#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int lettuce[50][50];
int n, m;

void sol(int y, int x)
{
	if(y>=n || x>=m || y<0 || x<0)
		return;
	if(lettuce[y][x])
	{
		lettuce[y][x] = 0;
		sol(y, x+1);
		sol(y+1, x);
		sol(y-1, x);
		sol(y, x-1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> results;
	int t;
	cin >> t;
	for(;t>0;t--)
	{
		int k, y, x, ret=0;
		memset(lettuce, 0, sizeof(lettuce));
		cin >> m >> n >> k;
		for(int i=0; i<k; i++)
		{
			cin >> x >> y;
			lettuce[y][x] = 1;
		}
		
		for(y=0; y<n; y++)
			for(x=0; x<m; x++)
				if(lettuce[y][x])
                {
					ret++;
					sol(y, x);
				}
		results.push_back(ret);
	}
	
	for(int i=0; i<results.size(); i++)
		cout << results[i] << endl;
	return 0;
}