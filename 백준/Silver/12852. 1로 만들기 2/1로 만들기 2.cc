#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

void bfs(int start)
{
	vector<int> visited(start+1, 0);
	queue<tuple<int,int,int>> q;
	q.push(make_tuple(start, 0, 0));
	
	while(!q.empty())
	{
		auto here = q.front();
		int here_num = get<0>(here);
		int next_dist = get<1>(here) + 1;
		int prev_num = get<2>(here);
		q.pop();
		
		if(visited[here_num])
			continue;
		visited[here_num] = prev_num;
		
		if(here_num == 1)
		{
			cout << next_dist-1 << '\n';
			break;
		}
		
		if(here_num % 3 == 0)
			q.push(make_tuple(here_num/3, next_dist, here_num));
		if(here_num % 2 == 0)
			q.push(make_tuple(here_num/2, next_dist, here_num));
		q.push(make_tuple(here_num-1, next_dist, here_num));
	}
	
	vector<int> path = {1};
	while(path.back() != start)
		path.push_back(visited[path.back()]);

	for(int i=path.size()-1; i>=0; i--)
		cout << path[i] << " ";
	cout << '\n';
}

int main()
{
	int n;
	cin >> n;
	bfs(n);
	return 0;
}