#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, t;
int board[101][101];
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
bool visited[101][101];

int bfs()
{
	int ret = 987654321;
	
	queue<pair<int,pair<int,int>>> q;
	q.push(make_pair(0, make_pair(0, 0)));
	visited[0][0] = true;
	
	while(!q.empty())
	{
		int here_dist = q.front().first;
		int here_y = q.front().second.first;
		int here_x = q.front().second.second;
		q.pop();
		
		if(here_y == n-1 && here_x == m-1) ret = min(ret, here_dist);
		else if(board[here_y][here_x] == 2) ret = min(ret, here_dist+(n-1-here_y)+(m-1-here_x));
		
		for(int i=0; i<4; i++)
		{
			int next_y = here_y + dy[i], next_x = here_x + dx[i];
			if(next_y < 0 || n <= next_y || next_x < 0 || m <= next_x || visited[next_y][next_x] || board[next_y][next_x] == 1) continue;
			q.push(make_pair(here_dist+1, make_pair(next_y, next_x)));
			visited[next_y][next_x] = true;
		}
	}
	
	return ret;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m >> t;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> board[i][j];
	
	memset(visited, false, sizeof(visited));
	int ret = bfs();
	if(ret > t) cout << "Fail\n";
	else cout << ret << '\n';
	return 0;
}