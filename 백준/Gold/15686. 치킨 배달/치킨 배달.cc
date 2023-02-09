#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int n, m;
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
vector<vector<int>> board;
vector<vector<vector<int>>> dist;

void bfs(pair<int,int>start_pos, int dist_index)
{
	queue<pair<int,int>> q;
	q.push(start_pos);
	dist[dist_index][start_pos.first][start_pos.second] = 0;
	
	while(!q.empty())
	{
		auto here = q.front();
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int nextY = dy[i] + here.first, nextX = dx[i] + here.second;
			if(nextY < 0 || nextY >= n || nextX <0 || nextX >= n || dist[dist_index][nextY][nextX] != -1) continue;
			dist[dist_index][nextY][nextX] = dist[dist_index][here.first][here.second] + 1;
			q.push(make_pair(nextY, nextX));
		}
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	board = vector<vector<int>> (n, vector<int>(n));
	vector<pair<int,int>> chicken_house_poses, house_poses;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 1)
			{
				house_poses.push_back(make_pair(i, j));
			}
			else if(board[i][j] == 2)
			{
				chicken_house_poses.push_back(make_pair(i, j));
				dist.push_back(vector<vector<int>>(n, vector<int>(n, -1)));
			}
		}
	
	for(int i=0; i<chicken_house_poses.size(); i++)
		bfs(chicken_house_poses[i], i);
	
	int ret = 987654321;
	vector<bool> picked_chicken_houses(chicken_house_poses.size(), false);
	for(int i=0; i<m; i++)
		picked_chicken_houses[i] = true;
	do{
		vector<int> chicken_dist(house_poses.size(), 100);
		for(int i=0; i<picked_chicken_houses.size(); i++)
			if(picked_chicken_houses[i])
			{
				for(int j=0; j<house_poses.size(); j++)
					chicken_dist[j] = min(chicken_dist[j], dist[i][house_poses[j].first][house_poses[j].second]);
			}
		
		int sum_chicken_dist = 0;
		for(int j=0; j<chicken_dist.size(); j++)
			sum_chicken_dist += chicken_dist[j];
		ret = min(ret, sum_chicken_dist);
	}while(prev_permutation(picked_chicken_houses.begin(), picked_chicken_houses.end()));
	
	cout << ret << '\n';
	return 0;
}