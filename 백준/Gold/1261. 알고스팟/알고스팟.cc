#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

#define INF 987654321

using namespace std;

int n, m;
int board[101][101];
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
vector<vector<int>> dist (101, vector<int>(101, INF));

void dijkstra(int start_y, int start_x)
{
	dist[start_y][start_x] = 0;

	priority_queue<tuple<int,int,int>> pq;
	pq.push(make_tuple(0, start_y, start_x));

	while(!pq.empty())
	{
		auto pq_top = pq.top();
		int cost = -get<0>(pq_top), here_y = get<1>(pq_top), here_x = get<2>(pq_top);
		pq.pop();

		if(cost > dist[here_y][here_x]) continue;
		for(int i=0; i<4; i++)
		{
			int next_y = here_y + dy[i], next_x = here_x + dx[i];
			if(0 <= next_y && next_y < n && 0 <= next_x && next_x < m)
			{
				int next_dist = cost + board[next_y][next_x];
				if(next_dist < dist[next_y][next_x])
				{
					dist[next_y][next_x] = next_dist;
					pq.push(make_tuple(-next_dist, next_y, next_x));
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> m >> n;

	string temp;
	for(int i=0; i<n; i++)
	{
		cin >> temp;
		for(int j=0; j<m; j++)
			if(temp[j] == '0')
				board[i][j] = 0;
			else
				board[i][j] = 1;
	}

	dijkstra(0, 0);
	cout << dist[n-1][m-1] << '\n';
	return 0;
}