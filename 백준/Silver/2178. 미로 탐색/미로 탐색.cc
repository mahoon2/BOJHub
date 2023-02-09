#include <iostream>
#include <string>
#include <queue>
#include <utility>

int n, m;
int board[100][100] = {0};
int dist[100][100] = {0};
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

using namespace std;

void bfs(int y, int x)
{
	queue<pair<int,int>> q;
	q.push(make_pair(y, x));
	dist[y][x] = 1;
	
	while(!q.empty())
	{
		pair<int,int> here = q.front();
		q.pop();
		
		int next_y, next_x;
		for(int i=0; i<4; i++)
		{
			next_y = here.first + dy[i];
			next_x = here.second + dx[i];
			if(next_y<0 || next_y>=n || next_x<0 || next_x>=m || board[next_y][next_x] == 0 || dist[next_y][next_x]) continue;
			
			q.push(make_pair(next_y, next_x));
			dist[next_y][next_x] = dist[here.first][here.second] + 1;
			
			if(next_y == n-1 && next_x == m-1) return;
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	string temp;
	for(int i=0; i<n; i++)
	{
		cin >> temp;
		for(int j=0; j<m; j++)
		{
			if(temp[j] == '1') board[i][j] = 1;
		}
	}
	
	bfs(0, 0);
	cout << dist[n-1][m-1] << '\n';
	
	return 0;
}