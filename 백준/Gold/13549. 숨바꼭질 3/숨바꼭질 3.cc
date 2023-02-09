#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#define INF 987654321

using namespace std;

int n, k;
vector<int> dist;

void bfs(int start)
{
	deque<int> dq;
	dq.push_back(start);
	dist[start] = 0;
	
	while(!dq.empty())
	{
		int here = dq.front();
		dq.pop_front();
		//cout << "Here: " << here << '\n';
		
		if(here == k) return;
		if(here > k)
		{
			if(dist[here-1] == -1)
			{
				dist[here-1] = dist[here] + 1;
				dq.push_back(here-1);
			}
			continue;
		}
		if(here == 0)
		{
			if(dist[here+1] == -1)
			{
				dist[here+1] = dist[here] + 1;
				dq.push_back(here+1);
			}
			continue;
		}
		
		if(dist[2*here] == -1)
		{
			dist[2*here] = dist[here];
			dq.push_front(2*here);
		}
		if(dist[here-1] == -1)
		{
			dist[here-1] = dist[here] + 1;
			dq.push_back(here-1);
		}
		if(dist[here+1] == -1)
		{
			dist[here+1] = dist[here] + 1;
			dq.push_back(here+1);
		}
	}
}

int main()
{
	cin >> n >> k;
	dist = vector<int>(200001, -1);
	if(k <= n)
	{
		cout << n-k << '\n';
		return 0;
	}
	bfs(n);
	cout << dist[k] << '\n';
	return 0;
}