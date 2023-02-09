#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n, k, cnt=0;
vector<int> visited;

void bfs(int start)
{
	queue<pair<int,int>> q;
	q.push(make_pair(start, 0));
	visited[start] = 0;
	
	while(!q.empty())
	{
		int here = q.front().first;
		int here_dist = q.front().second;
		q.pop();
		
		if(here == k && here_dist <= visited[k]) cnt++;
		
		if(here < k)
		{
			if(here+1 <= k && here_dist+1 <= visited[here+1])
			{
				q.push(make_pair(here+1, here_dist+1));
				visited[here+1] = here_dist + 1;
			}
			if(here*2 <= 200000 && here_dist+1 <= visited[here*2])
			{
				q.push(make_pair(here*2, here_dist+1));
				visited[here*2] = here_dist + 1;
			}
		}
		if(0 <= here-1 && here_dist+1 <= visited[here-1])
		{
			q.push(make_pair(here-1, here_dist+1));
			visited[here-1] = here_dist + 1;
		}
	}
	
	cout << visited[k] << '\n';
	cout << cnt << '\n';
}

int main()
{
	cin >> n >> k;
	visited = vector<int> (200001, 100001);
	bfs(n);
	return 0;
}