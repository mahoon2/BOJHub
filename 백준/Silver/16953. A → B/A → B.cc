#include <iostream>
#include <queue>
#include <utility>

typedef long long ll;
using namespace std;

ll a, b;

void bfs(ll start)
{
	queue<pair<ll,int>> q;
	q.push(make_pair(start, 0));
	
	while(!q.empty())
	{
		auto here = q.front();
		int next_dist = here.second + 1;
		q.pop();
		
		if(here.first == b)
		{
			cout << next_dist << '\n';
			return;
		}
		if(here.first*2 <= b)
			q.push(make_pair(here.first*2, next_dist));
		if(here.first*10+1 <= b)
			q.push(make_pair(here.first*10+1, next_dist));
	}
	cout << -1 << '\n';
}

int main()
{
	cin >> a >> b;
	bfs(a);
	return 0;
}