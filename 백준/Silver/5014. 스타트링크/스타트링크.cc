#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, start, dest, up, down;
bool visited[1000001];

int bfs()
{
	queue<pair<int,int>> q;
	q.push(make_pair(0, start));
	
	while(!q.empty())
	{
		int cnt = q.front().first, here = q.front().second;
		q.pop();
		
		if(visited[here]) continue;
		visited[here] = true;
		if(here == dest) return cnt;
		
		if(1 <= here+up && here+up <= n && !visited[here+up])
		{
			q.push(make_pair(cnt+1, here+up));
		}
		if(1 <= here-down && here-down <= n && !visited[here-down])
		{
			q.push(make_pair(cnt+1, here-down));
		}
	}
	
	return -1;
}

int main()
{
	cin >> n >> start >> dest >> up >> down;
	memset(visited, false, sizeof(visited));
	
	int ret = bfs();
	if(ret == -1) cout << "use the stairs\n";
	else cout << ret << '\n';
	return 0;
}