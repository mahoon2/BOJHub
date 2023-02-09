#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#define INF 987654321

using namespace std;

int cnt = 0;
int shark_size = 2;
int shark_has_eaten = 0;
int shark_y, shark_x;
int board[20][20];
int board_distance[20][20];
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
int n;

int bfs(int start_y, int start_x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(start_y, start_x));
	int prey_min_board_distance = INF;
	
	while(!q.empty())
	{
		pair<int, int> current_pos = q.front();
		q.pop();
		for(int i=0; i<4; i++)
		{
			int next_y = current_pos.first + dy[i];
			int next_x = current_pos.second + dx[i];
			if(next_y < 0 || next_y >= n || next_x < 0 || next_x >= n || board_distance[next_y][next_x] != -1 || board[next_y][next_x] > shark_size) continue;
			board_distance[next_y][next_x] = board_distance[current_pos.first][current_pos.second] + 1;
			q.push(make_pair(next_y, next_x));
			if(board[next_y][next_x] && board[next_y][next_x] < shark_size)
				prey_min_board_distance = min(prey_min_board_distance, board_distance[next_y][next_x]);
		}
	}
	
	return prey_min_board_distance;
}

int main()
{
	int temp;
	memset(board, -1, sizeof(board));
	
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			cin >> temp;
			board[i][j] = temp;
			if(temp == 9) {shark_y=i; shark_x=j;}
		}
	
	while(true)
	{
		memset(board_distance, -1, sizeof(board_distance));
		board_distance[shark_y][shark_x] = 0;
		int prey_min_board_distance = bfs(shark_y, shark_x);
		
		/*for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				cout << board_distance[i][j] << " ";
			cout << '\n';
		}
		cout << '\n';*/
		
		if(prey_min_board_distance == INF)
			break;
		
		int next_prey_y, next_prey_x, i=0;
		bool while_escape = false;
		while(i<n && !while_escape)
		{
			for(int j=0; j<n; j++)
				if(board[i][j] && board[i][j] < shark_size && prey_min_board_distance == board_distance[i][j])
				{
					next_prey_y = i;
					next_prey_x = j;
					while_escape = true;
					break;
				}
			i++;
		}
		
		board[shark_y][shark_x] = 0;
		shark_y = next_prey_y;
		shark_x = next_prey_x;
		board[next_prey_y][next_prey_x] = 9;
		cnt += board_distance[next_prey_y][next_prey_x];
		shark_has_eaten++;
		if(shark_has_eaten == shark_size) {shark_size++; shark_has_eaten=0;}
	}
	cout << cnt << '\n';
	return 0;
}