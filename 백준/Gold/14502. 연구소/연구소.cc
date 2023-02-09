#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
int n, m, safe_area = 0;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<pair<int,int>> virus_pos;

void bfs()
{
	queue<pair<int,int>> q;
	for(auto i: virus_pos)
	{
		q.push(i);
		visited[i.first][i.second] = true;
	}
	
	while(!q.empty())
	{
		auto here = q.front();
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int next_y = dy[i] + here.first, next_x = dx[i] + here.second;
			if(next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || visited[next_y][next_x] || board[next_y][next_x] == 1) continue;
			visited[next_y][next_x] = true;
			q.push(make_pair(next_y, next_x));
		}
	}
	
	int cnt = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(!visited[i][j] && board[i][j] == 0)
				cnt++;
	
	safe_area = max(safe_area, cnt);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	
	vector<pair<int,int>> wall_candidate;
	board = vector<vector<int>> (n, vector<int>(m));
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 0)
				wall_candidate.push_back(make_pair(i, j));
			else if(board[i][j] == 2)
				virus_pos.push_back(make_pair(i, j));
		}
	
	for(int i=0; i<wall_candidate.size()-2; i++)
	{
		board[wall_candidate[i].first][wall_candidate[i].second] = 1;
		for(int j=i+1; j<wall_candidate.size()-1; j++)
		{
			board[wall_candidate[j].first][wall_candidate[j].second] = 1;
			for(int k=j+1; k<wall_candidate.size(); k++)
			{
				board[wall_candidate[k].first][wall_candidate[k].second] = 1;
				visited = vector<vector<bool>> (n, vector<bool>(m, false));
				bfs();
				board[wall_candidate[k].first][wall_candidate[k].second] = 0;
			}
			board[wall_candidate[j].first][wall_candidate[j].second] = 0;
		}
		board[wall_candidate[i].first][wall_candidate[i].second] = 0;
	}
	
	cout << safe_area << '\n';
	return 0;
}