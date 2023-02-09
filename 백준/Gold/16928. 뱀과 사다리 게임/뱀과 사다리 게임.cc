#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

deque<int> dq;
int adj[101][101];
int dist[101];
bool visited[101] = {false};

int bfs(int start)
{
	dq.push_back(start);
	visited[start] = true;
	dist[start] = 0;
	
	while(!dq.empty())
	{
		int current = dq.front();
		dq.pop_front();
		if(current == 100)
			return dist[100];
		//cout << current << '\n';
		
		for(int i=1; i<101; i++)
		{
			if(adj[current][i] == 1 && !visited[i])
			{
				dq.push_back(i);
				visited[i] = true;
				dist[i] = dist[current] + 1;
			}
			if(adj[current][i] == 0)
			{
				dq.push_front(i);
				dist[i] = dist[current];
			}
		}
	}
}

int main()
{
	int n, m;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(adj, -1, sizeof(adj));
	
	cin >> n >> m;
	int x, y;
	bool ladder_or_snake[101] = {false};
	for(int i=0; i<n+m; i++)
	{
		cin >> x >> y;
		adj[x][y] = 0;
		ladder_or_snake[x] = true;
	}
	for(int i=1; i<100; i++)
	{
		if(ladder_or_snake[i]) continue;
		for(int j=1; j<7; j++)
		{
			if(i+j > 101) continue;
			adj[i][i+j] = 1;
		}
	}
	
	cout << bfs(1) << '\n';
	return 0;
}