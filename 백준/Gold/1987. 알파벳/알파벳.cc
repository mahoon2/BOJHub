#include <iostream>

using namespace std;

int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
int r, c, ret=0;
int board[20][20];

void solve(int y, int x, int visited, int dist)
{
	ret = max(ret, dist);
	
	for(int i=0; i<4; i++)
	{
		int next_y = y + dy[i];
		int next_x = x + dx[i];
		
		if(next_y < 0 || next_y >= r || next_x < 0 || next_x >= c)
			continue;
		
		int bitmask = (1<<board[next_y][next_x]);
		if(!(visited & bitmask))
			solve(next_y, next_x, visited | bitmask, dist+1);
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> r >> c;
	
	char a;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
		{
			cin >> a;
			board[i][j] = a - 'A';
		}
	
	solve(0, 0, (1<<board[0][0]), 1);
	cout << ret << '\n';
	return 0;
}