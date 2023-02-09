#include <iostream>
#include <cstring>

short arr[101][101];
short visited[101];
int ret = 0;
int n;
using namespace std;

void sol(int node)
{
	ret++;
	visited[node] = 1;
//	cout << node << " visited" << endl;
	
	for(int i=1; i<=n; i++)
	{
		if(arr[node][i] == 1 && visited[i] == 0)
			sol(i);
	}
}

int main()
{
	memset(arr, 0, sizeof(arr));
	memset(visited, 0, sizeof(visited));
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m, temp1, temp2;
	cin >> n >> m;
	
	for(int i=0; i<m; i++)
	{
		cin >> temp1 >> temp2;
		arr[temp1][temp2] = 1;
		arr[temp2][temp1] = 1;
	}
	
	sol(1);
	cout << ret-1 << endl;
	return 0;
}