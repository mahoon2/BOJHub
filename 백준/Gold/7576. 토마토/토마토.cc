#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int m, n, board[1000][1000], dist[1000][1000];
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
bool visited[1000][1000] = {false};

void bfs(vector<pair<int, int>>& start_poses)
{
	queue<pair<int, int>> q;
	for(auto& start_pos: start_poses)
		q.push(start_pos);
	
	while(!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();
		pair<int, int> next_pos;
		for(int i=0; i<4; i++)
		{
			int next_y = pos.first + dy[i], next_x = pos.second + dx[i];
			if(next_y < 0 || next_y >= n || next_x < 0 || next_x >= m
			  || visited[next_y][next_x] || board[next_y][next_x] == -1)
				continue;
			if(dist[next_y][next_x] == -1)
			{
				dist[next_y][next_x] = dist[pos.first][pos.second] + 1;
				q.push(make_pair(next_y, next_x));
				visited[next_y][next_x] = true;
			}
			else
			{
				dist[next_y][next_x] = min(dist[next_y][next_x],
										   dist[pos.first][pos.second] + 1);
				q.push(make_pair(next_y, next_x));
				visited[next_y][next_x] = true;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	memset(dist, -1, sizeof(dist));
	cin >> m >> n;
	int temp;
	vector<pair<int, int>> start_poses;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			cin >> temp;
			board[i][j] = temp;
			if(temp == 1)
			{
				start_poses.push_back(make_pair(i, j));
				dist[i][j] = 0;
			}
		}
	
	/*cout << '\n';
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout << board[i][j] << " ";
		cout << '\n';
	}
	cout << '\n';*/

	bfs(start_poses);
	
	/*cout << '\n';
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout << dist[i][j] << " ";
		cout << '\n';
	}
	cout << '\n';*/
	
	int days_max = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(dist[i][j] == -1 && board[i][j] != -1)
			{
				cout << -1 << '\n';
				return 0;
			}
			else
				days_max = max(days_max, dist[i][j]);
	
	cout << days_max << '\n';
	return 0;
}